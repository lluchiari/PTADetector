#include "../../include/calibration/Settings.h"

void Settings::write(SETTING_STORAGE& fs) const
{
    fs << "{" << "BoardSize_Width"  << boardSize.width
       << "BoardSize_Height" << boardSize.height
       << "Square_Size"         << squareSize
       << "Calibrate_Pattern" << patternToUse
       << "Calibrate_NrOfFrameToUse" << nrFrames
       << "Calibrate_FixAspectRatio" << aspectRatio
       << "Calibrate_AssumeZeroTangentialDistortion" << calibZeroTangentDist
       << "Calibrate_FixPrincipalPointAtTheCenter" << calibFixPrincipalPoint

       << "Write_DetectedFeaturePoints" << bwritePoints
       << "Write_extrinsicParameters"   << bwriteExtrinsics
       << "Write_outputFileName"  << outputFileName

       << "Show_UndistortedImage" << showUndistorsed

       << "Input_FlipAroundHorizontalAxis" << flipVertical
       << "Input_Delay" << delay
       << "Input" << input
       << "}";
}

//void Settings::read(const SETTING_NODE
//                    & node)
//{
//    node["BoardSize_Width" ] >> boardSize.width;
//    node["BoardSize_Height"] >> boardSize.height;
//    node["Calibrate_Pattern"] >> patternToUse;
//    node["Square_Size"]  >> squareSize;
//    node["Calibrate_NrOfFrameToUse"] >> nrFrames;
//    node["Calibrate_FixAspectRatio"] >> aspectRatio;
//    node["Write_DetectedFeaturePoints"] >> bwritePoints;
//    node["Write_extrinsicParameters"] >> bwriteExtrinsics;
//    node["Write_outputFileName"] >> outputFileName;
//    node["Calibrate_AssumeZeroTangentialDistortion"] >> calibZeroTangentDist;
//    node["Calibrate_FixPrincipalPointAtTheCenter"] >> calibFixPrincipalPoint;
//    node["Input_FlipAroundHorizontalAxis"] >> flipVertical;
//    node["Show_UndistortedImage"] >> showUndistorsed;
//    node["Input"] >> input;
//    node["Input_Delay"] >> delay;
//    interprate();
//}

void Settings::read(string fileLocation)
{
    this->boardSize.width = 9;
    this->boardSize.height = 6;
    this->patternToUse = "CHESSBOARD";
    this->squareSize = 50;
    this->nrFrames = 25;
    this->aspectRatio = 1;
    this->bwritePoints = 1;
    this->bwriteExtrinsics = 1;
    this->outputFileName = "out_camera_data.xml";
    this->calibZeroTangentDist = 1;
    this->calibFixPrincipalPoint = 1;
    this->flipVertical = 0;
    this->showUndistorsed = 1;
    this->input = fileLocation;
    this->delay = 100;
    interprate();
}

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
            ss >> cameraID;
            inputType = CAMERA;
        }
        else
        {
            if (isListOfImages(input) && readStringList(input, imageList))
            {
                inputType = IMAGE_LIST;
                nrFrames = (nrFrames < (int)imageList.size()) ? nrFrames : (int)imageList.size();
            }
            else
                inputType = VIDEO_FILE;
        }
        if (inputType == CAMERA)
            inputCapture.open(cameraID);
        if (inputType == VIDEO_FILE)
            inputCapture.open(input);
        if (inputType != IMAGE_LIST && !inputCapture.isOpened())
            inputType = INVALID;
    }
    if (inputType == INVALID)
    {
        cerr << " Inexistent input: " << input;
        goodInput = false;
    }

    flag = 0;
    if(calibFixPrincipalPoint) flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
    if(calibZeroTangentDist)   flag |= CV_CALIB_ZERO_TANGENT_DIST;
    if(aspectRatio)            flag |= CV_CALIB_FIX_ASPECT_RATIO;


    calibrationPattern = NOT_EXISTING;
    if (!patternToUse.compare("CHESSBOARD")) calibrationPattern = CHESSBOARD;
    if (!patternToUse.compare("CIRCLES_GRID")) calibrationPattern = CIRCLES_GRID;
    if (!patternToUse.compare("ASYMMETRIC_CIRCLES_GRID")) calibrationPattern = ASYMMETRIC_CIRCLES_GRID;
    if (calibrationPattern == NOT_EXISTING)
    {
        cerr << " Inexistent camera calibration mode: " << patternToUse << endl;
        goodInput = false;
    }
    atImageList = 0;
}

Mat Settings::nextImage(){
    Mat result;
    if( this->inputCapture.isOpened() )
    {
        Mat view0;
        this->inputCapture >> view0;
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
