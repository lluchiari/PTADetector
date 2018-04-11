#ifndef __PTA_DETECTOR__
#define __PTA_DETECTOR__

//Qt Libs
#include <QObject>
#include <QWidget>

// STL Libs
#include <iostream>
#include <fstream>
#include <string>

// OpenCV Libs
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//Internal Lib
#include "./PTAWindow.h"
#include "./Myloger.h"
#include "./filter/CannyFilter.h"
#include "./calibration/Calibration.h"
#include <common.h>

using namespace cv;
using namespace std;


//#ifdef _WIN64
//#endif

//#ifdef __linux__
//#endif

class PTADetector : public QObject
{
    Q_OBJECT

public:
    PTADetector(PTAWindow *, MyLoger *, QObject *parent=0);
    ~PTADetector();

public:
    Mat borderDetecting(Mat);
    Mat loadImages(string);
    int configCalibration();
    void runCalibration();
    int run();

    // Seters
    void setWidget(PTAWindow *);

    // Geters
    PTAWindow *getWidget();

public slots:
    void callCalibration();

private:
    Calibration *_calibModel;
    PTAWindow *_view;
    MyLoger *_log;
    int _errorFlag;
};


#endif
