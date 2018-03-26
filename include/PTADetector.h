#ifndef __PTA_DETECTOR__
#define __PTA_DETECTOR__

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "./filter/CannyFilter.h"
#include "./calibration/Calibration.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace cv;
using namespace std;


#ifdef _WIN64   
#endif

#ifdef __linux__   
#endif

Mat loadImages(string);
Mat borderDetecting(Mat);

class PTADetector{
  public:
    PTADetector();
    ~PTADetector();

   public:
    int run();
};


#endif
