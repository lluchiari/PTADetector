#ifndef __PTAWINDOW_H__
#define __PTAWINDOW_H__

#define MAX_CAM_QTY 7

//Qt Libs
#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

// STL Libs
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

// OpenCV Libs
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

//Internal Lib
#include <common.h>

using namespace cv;
using namespace std;

namespace Ui {
class PTAWindow;
}

class PTAWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PTAWindow(QWidget *parent = 0);
    ~PTAWindow();

private slots:
    void on_ConfirmPushButton_clicked();

    void on_LoadConfigFilePushButton_clicked();

    void on_StackImageFilePushButton_clicked();

    void on_OutputFilePushButton_clicked();

    void on_ControlSelector_ImageStackRadioButton_clicked();

    void on_ControlSelector_CameraRadioButton_clicked();

    void on_ControlSelector_VideoRadioButton_clicked();

public slots:
    void writeLog(string, int);

signals:
    void callCalibration();

private:
    Ui::PTAWindow *ui;

    bool _CameraRadioButton;
    bool _ImageStackRadioButton;
    bool _VideoRadioButton;

public:
    string _inputSettingsFile;
    string _inputStackImageFile;
    string _OutputFileURL;
};

#endif // PTAWINDOW_H
