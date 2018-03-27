#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>

#include <opencv2/core/core.hpp>

#define DEBUG 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConnect_Camera_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
