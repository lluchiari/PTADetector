#ifndef __PTA_DETECTOR__
#define __PTA_DETECTOR__

#include <QObject>
#include <QWidget>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "./ptawindow.h"
#include "./filter/CannyFilter.h"
#include "./calibration/Calibration.h"
#include <common.h>

#include <iostream>
#include <fstream>
#include <string>

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
    PTADetector(PTAWindow *, QObject *parent=0);
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
    int _errorFlag;
};


#endif
