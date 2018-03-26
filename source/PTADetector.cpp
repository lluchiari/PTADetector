#include "../include/PTADetector.h"


PTADetector::PTADetector()
{

}

PTADetector::~PTADetector(){

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
Mat loadImages(string filename)
{
    Mat src;
    src = imread(filename, CV_LOAD_IMAGE_COLOR);
    return src;
}


//Mat borderDetecting(Mat src)
//{
//	int i, j;

//}
