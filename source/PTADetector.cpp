#include "../include/PTADetector.h"

PTADetector::PTADetector(QWidget *wid, QObject *parent):QObject(parent)
{    
    this->_view = wid;
    this->_calib = new Calibration(wid);
    QObject::connect(this->_view, SIGNAL(callCalibration()), detector, SLOT(setCalibrate()));
}

PTADetector::~PTADetector(){
    delete _calib;
}

void PTADetector::setWidget(QWidget *wid)
{
    this->_view = wid;
}

QWidget *PTADetector::getWidget()
{
    return this->_view;
}


void PTADetector::runCalibration(){
    // Check if the reading process is working correctlly
    if(_calib->readSettings() != 0)
    {
        cerr << "Error on input files!" << std::endl;
    }
    else{
        // Make the calibration
        if(DEBUG) {std::cout << "Calibration Starting" << std::endl;}
        _calib->calibrate();
    }

    //    //QString inputSettingsFile = QFileDialog::getOpenFileName(&w, "Open a file", "", "Configuration File (*.xml)");
    //    //std::cout << inputSettingsFile.toUtf8().constData();

}

void PTADetector::setCalibrate(){
    cout << "Execute Calibration!" << endl;
}

int PTADetector::run()
{
	// Simulation Parameters
    string shapeFileName = "./images/shapes/Complex3.png";
    string shapeName = "Complex1";

	// Chose the filter type
	//string testType = "normalFilter";	//blur
	//string testType = "gaussianBlur";
	string testType = "bilateralFilter";
	
	// Choose the Threshold Parameter	
	int thStart = 0;
	int thEnd = 20;
	int thStep = 20;

	// Image variables
	Mat shape, shapeGray;

	shape = loadImages(shapeFileName);

	if (!shape.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	
    cout << "Foi pro gol!";
    exit(0);

	// Convert the image to grayscale
	cvtColor(shape, shapeGray, CV_BGR2GRAY);

	
	// Canny Filter Parameters
	CannyFilter cFilter;
	cFilter.setEdgeThreshold(1);
	cFilter.setRatio(3);
	cFilter.setKernelSize(3);
	cFilter.setNoiseRedType(testType);

	// Return Borders
	Mat dst;
	dst.create(shapeGray.size(), shapeGray.type());

	// Compression Parameters
	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	int i;
	for (i = thStart; i < thEnd; i = i+ thStep)
	{
		// Run the filter analysis
		cFilter.setLowThreshold(i);
		dst = cFilter.apply(shapeGray);

		// Catching the Borders
		//Mat border = borderDetecting(dst);

		string filename, aux;
		aux = testType + to_string(i) + ".png";
        filename = "../images/results/" + shapeName + "/" + aux;
		try {
			imwrite(filename, dst, compression_params);
		}
		catch (runtime_error& ex) {
			fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
			return 1;
		}
		string debugString = "File " + aux + "Saved PNG file with alpha data.\n";
		cout <<  debugString;
	}
	
	// Create a window for display.
    namedWindow("Edge Map", CV_WINDOW_AUTOSIZE);

	// Show our image inside it.
    imshow("Display Borders", dst);
	
	// Wait for a keystroke in the window
    waitKey(0);
	
	return 0;
}

/**
* @function loadImages
* @param filename
* @brief Load imagens from a specified file
*/
Mat PTADetector::loadImages(string filename)
{
    Mat src;
    src = imread(filename, CV_LOAD_IMAGE_COLOR);
    return src;
}


Mat PTADetector::borderDetecting(Mat src)
{
    Mat result;
    //int i, j;
    return result;

}
