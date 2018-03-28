#ifndef __CALIBRATION_H__
#define __CALIBRATION_H__

#include <QFileDialog>
#include <QWidget>
#include <QString>

#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "../mainwindow.h"
#include "./Settings.h"
#include <common.h>

class Calibration
{
public:
    Calibration(QWidget *);
    Calibration();
	~Calibration();

    int readSettings();
//    int parseInput();
    int calibrate();

private:
    Settings _s;            //Setting file to be read by the funciton
    QWidget *_widget;

    enum {
        DETECTION = 0,      // This mode takes the images direct from a file
        CAPTURING = 1,      // This mode is capturing images from the camera or image list
        CALIBRATED = 2      // This mode indicate that is already calibrated
    };

private:
    bool runCalibrationAndSave(Settings&, Size, Mat&, Mat&, vector<vector<Point2f>>);
    void saveCameraParams( Settings&, Size&, Mat&, Mat&, const vector<Mat>&, const vector<Mat>&,
                                  const vector<float>&, const vector<vector<Point2f> >&, double);
    bool runCalibration( Settings&, Size&, Mat&, Mat&, vector<vector<Point2f>>, vector<Mat>&, vector<Mat>&,
                                vector<float>&,  double&);
};

#endif
