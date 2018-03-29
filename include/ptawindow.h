#ifndef PTAWINDOW_H
#define PTAWINDOW_H

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

private:
    Ui::PTAWindow *ui;

    bool _CameraRadioButton;
    bool _ImageStackRadioButton;
    bool _VideoRadioButton;

    string _inputSettingsFile;
    string _inputStackImageFile;
};

#endif // PTAWINDOW_H
