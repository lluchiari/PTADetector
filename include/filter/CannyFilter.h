#pragma once
#ifndef __CANNY_H__
#define __CANNY_H__

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

class CannyFilter
{
public:
	// Constructors
	CannyFilter();
	CannyFilter(int, int, int, int);

	// Constants
	int const _max_lowThreshold = 100;
	int const _windowSize = 3;

	//Functions Seters
	void setEdgeThreshold(int);
	void setLowThreshold(int);
	void setRatio(int);
	void setKernelSize(int);
	void setNoiseRedType(string);
	
	//Functions Geters
	int getEdgeThreshold(void);
	int getLowThreshold(void);
	int getRatio(void);
	int getKernelSize(void);

	// Normal Functions
	Mat apply(Mat);

	//Destructor
	~CannyFilter();

private:
	cv::Mat _dst, _detectedEdges;
	int _size, _type;
	int _edgeThresh;
	int _lowThreshold;
	int _ratio;
	int _kernelSize;
	string _noiseRedType;
};

#endif
