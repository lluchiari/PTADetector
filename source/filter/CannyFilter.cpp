#include "../../include/filter/CannyFilter.h"


CannyFilter::CannyFilter()
{
	
}

CannyFilter::CannyFilter(int edgeThresh, int lowThreshold, int ratio, int kernelSize)
{
	this->_edgeThresh = edgeThresh;
	this->_lowThreshold = lowThreshold;
	this->_ratio = ratio;
	this->_kernelSize = kernelSize;
}

CannyFilter::~CannyFilter()
{
}


/**
* @function CannyThreshold
* @brief Trackbar callback - Canny thresholds input with a ratio 1:3
*/
cv::Mat CannyFilter::apply(cv::Mat srcGray)
{
	if (this->_noiseRedType == "normalFilter") {
		// Reduce noise with a kernel 
		blur(srcGray, this->_detectedEdges, Size(this->_windowSize, this->_windowSize));
	}
	else if (this->_noiseRedType == "gaussianBlur") {
		GaussianBlur(srcGray, this->_detectedEdges, Size(this->_windowSize, this->_windowSize), 0, 0);
	}
	else if (this->_noiseRedType == "bilateralFilter") {
		bilateralFilter(srcGray, this->_detectedEdges, this->_windowSize, this->_windowSize * 2, this->_windowSize / 2);
	}
	else {
		// Reduce noise with a kernel 
		blur(srcGray, this->_detectedEdges, Size(this->_windowSize, this->_windowSize));
	}

	// Canny detector
	cv::Canny(this->_detectedEdges, this->_detectedEdges, this->_lowThreshold, (this->_lowThreshold*this->_ratio), this->_kernelSize);

	// Using Canny's output as a mask, we display our result
	Mat _dst;
	_dst = Scalar::all(0);

	srcGray.copyTo(_dst, this->_detectedEdges);
	
	return _dst;
}

/**
* @function
* @brief
*/
void CannyFilter::setEdgeThreshold(int eTh)
{
	this->_edgeThresh = eTh;
}

/**
* @function
* @brief
*/
void CannyFilter::setLowThreshold(int th)
{
	if (th > this->_max_lowThreshold) {
		this->_lowThreshold = this->_max_lowThreshold;
	}
	else {
		this->_lowThreshold = th;
	}
}

/**
* @function
* @brief
*/
void CannyFilter::setRatio(int rt)
{
	this->_ratio = rt;
}

/**
* @function
* @brief
*/
void CannyFilter::setKernelSize(int ks)
{
	this->_kernelSize = ks;
}

void CannyFilter::setNoiseRedType(string whichType)
{
	this->_noiseRedType = whichType;
}

int CannyFilter::getEdgeThreshold(void)
{
	return _edgeThresh;
}

int CannyFilter::getLowThreshold(void)
{
	return _lowThreshold;
}

int CannyFilter::getRatio(void)
{
	return _ratio;
}

int CannyFilter::getKernelSize(void)
{
	return _kernelSize;
}

