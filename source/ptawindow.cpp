#include "../include/ptawindow.h"
#include "ui_ptawindow.h"

PTAWindow::PTAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTAWindow)
{
    ui->setupUi(this);
}

PTAWindow::~PTAWindow()
{
    delete ui;
}
