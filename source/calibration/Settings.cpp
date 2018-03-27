#include "../../include/calibration/Settings.h"

//void Settings::write(SETTING_STORAGE& fs) const
//{
//    fs << "{" << "BoardSize_Width"  << this->boardSize.width
//       << "BoardSize_Height" << this->boardSize.height
//       << "Square_Size"         << this->squareSize
//       << "Calibrate_Pattern" << this->_patternToUse
//       << "Calibrate_NrOfFrameToUse" << this->nrFrames
//       << "Calibrate_FixAspectRatio" << this->aspectRatio
//       << "Calibrate_AssumeZeroTangentialDistortion" << this->calibZeroTangentDist
//       << "Calibrate_FixPrincipalPointAtTheCenter" << this->calibFixPrincipalPoint

//       << "Write_DetectedFeaturePoints" << this->bwritePoints
//       << "Write_extrinsicParameters"   << this->bwriteExtrinsics
//       << "Write_outputFileName"  << this->outputFileName

//       << "Show_UndistortedImage" << this->showUndistorsed

//       << "Input_FlipAroundHorizontalAxis" << this->flipVertical
//       << "Input_Delay" << this->delay
//       << "Input" << this->input
//       << "}";
//}

//void Settings::read(const SETTING_NODE
//                    & node)
//{
//    node["BoardSize_Width" ] >> this->boardSize.width;
//    node["BoardSize_Height"] >> this->boardSize.height;
//    node["Calibrate_Pattern"] >> this->_patternToUse;
//    node["Square_Size"]  >> this->squareSize;
//    node["Calibrate_NrOfFrameToUse"] >> this->nrFrames;
//    node["Calibrate_FixAspectRatio"] >> this->aspectRatio;
//    node["Write_DetectedFeaturePoints"] >> this->bwritePoints;
//    node["Write_extrinsicParameters"] >> this->bwriteExtrinsics;
//    node["Write_outputFileName"] >> this->outputFileName;
//    node["Calibrate_AssumeZeroTangentialDistortion"] >> this->calibZeroTangentDist;
//    node["Calibrate_FixPrincipalPointAtTheCenter"] >> this->calibFixPrincipalPoint;
//    node["Input_FlipAroundHorizontalAxis"] >> this->flipVertical;
//    node["Show_UndistortedImage"] >> this->showUndistorsed;
//    node["Input"] >> this->input;
//    node["Input_Delay"] >> this->delay;
//    interprate();
//}

/**
 * @brief This function reads the xml file and fullfill the class variables
 * @param fileLocation
 */
void Settings::read(string fileLocation)
{
    this->boardSize.width = 9;
    this->boardSize.height = 6;
    this->_patternToUse = "CHESSBOARD";
    this->squareSize = 50;
    this->nrFrames = 25;
    this->aspectRatio = 1;
    this->bwritePoints = 1;
    this->bwriteExtrinsics = 1;
    this->outputFileName = "out_camera_data.txt";
    this->calibZeroTangentDist = 1;
    this->calibFixPrincipalPoint = 1;
    this->flipVertical = 0;
    this->showUndistorsed = 1;
    this->input = fileLocation;
    this->delay = 100;
    interprate();
}

/**
 * @brief This function interprate the configure file given and check for errors
 *
 */
void Settings::interprate()
{
    goodInput = true;
    if (boardSize.width <= 0 || boardSize.height <= 0)
    {
        cerr << "Invalid Board size: " << boardSize.width << " " << boardSize.height << endl;
        goodInput = false;
    }
    if (squareSize <= 10e-6)
    {
        cerr << "Invalid square size " << squareSize << endl;
        goodInput = false;
    }
    if (nrFrames <= 0)
    {
        cerr << "Invalid number of frames " << nrFrames << endl;
        goodInput = false;
    }

    if (input.empty())      // Check for valid input
        inputType = INVALID;
    else
    {
        if (input[0] >= '0' && input[0] <= '9')
        {
            stringstream ss(input);
            ss >> this->cameraID;
            inputType = CAMERA;
        }
        else
        {
            if (isListOfImages(input) && readStringList(input, this->imageList))
            {
                inputType = IMAGE_LIST;
                this->nrFrames = (this->nrFrames < (int)imageList.size()) ? this->nrFrames : (int)imageList.size();
            }
            else
                inputType = VIDEO_FILE;
        }
        if (inputType == CAMERA)
            this->inputCapture.open(this->cameraID);
        if (inputType == VIDEO_FILE)
            this->inputCapture.open(input);
        if (inputType != IMAGE_LIST && !this->inputCapture.isOpened())
            inputType = INVALID;
    }
    if (inputType == INVALID)
    {
        cerr << " Inexistent input: " << input;
        goodInput = false;
    }

    this->flag = 0;
    if(this->calibFixPrincipalPoint) this->flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
    if(this->calibZeroTangentDist)   this->flag |= CV_CALIB_ZERO_TANGENT_DIST;
    if(this->aspectRatio)            this->flag |= CV_CALIB_FIX_ASPECT_RATIO;



    // Chosing the kind of calibration pattern to be used
    this->calibrationPattern = NOT_EXISTING;
    if (!this->_patternToUse.compare("CHESSBOARD")) this->calibrationPattern = CHESSBOARD;
    if (!this->_patternToUse.compare("CIRCLES_GRID")) this->calibrationPattern = CIRCLES_GRID;
    if (!this->_patternToUse.compare("ASYMMETRIC_CIRCLES_GRID")) this->calibrationPattern = ASYMMETRIC_CIRCLES_GRID;
    if (this->calibrationPattern == NOT_EXISTING)
    {
        cerr << " Inexistent camera calibration mode: " << this->_patternToUse << endl;
        this->goodInput = false;
    }
    this->atImageList = 0;
}

Mat Settings::nextImage(){
    Mat result;
    if( this->inputCapture.isOpened() )
    {
        Mat view0;
        this->inputCapture >> view0;

        //TODO: is this really necessary?
        view0.copyTo(result);
    }
    else if( this->atImageList < (int)this->imageList.size() )
        result = imread(this->imageList[this->atImageList++], CV_LOAD_IMAGE_COLOR);

    return result;
}

bool Settings::readStringList( const string& filename, vector<string>& l )
{
    l.clear();
    SETTING_STORAGE fs(filename, SETTING_STORAGE::READ);
    if( !fs.isOpened() )
        return false;
    SETTING_NODE n = fs.getFirstTopLevelNode();
    if( n.type() != SETTING_NODE::SEQ )
        return false;
    SETTING_NODE_ITERATOR it = n.begin(), it_end = n.end();
    for( ; it != it_end; ++it )
        l.push_back((string)*it);
    return true;
}

bool Settings::isListOfImages( const string& filename)
{
    string s(filename);
    // Look for file extension
    if( s.find(".xml") == string::npos && s.find(".yaml") == string::npos && s.find(".yml") == string::npos )
        return false;
    else
        return true;
}
