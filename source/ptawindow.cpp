#include "../include/ptawindow.h"
#include "ui_ptawindow.h"

PTAWindow::PTAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTAWindow)
{
    ui->setupUi(this);
    ui->StackImageFileLineEdit->setEnabled(false);
    ui->StackImageFilePushButton->setEnabled(false);
}

PTAWindow::~PTAWindow()
{
    delete ui;
}

void PTAWindow::on_ConfirmPushButton_clicked()
{

    // Check if the form is correctlly filled. If yes run the calibration
    if(!ui->LoadConfigFileLineEdit->text().isEmpty()
            && !ui->StackImageFileLineEdit->text().isEmpty()
            && !ui->OutputFileLineEdit->text().isEmpty()
            && (ui->ControlSelector_CameraRadioButton->isChecked() ||
            ui->ControlSelector_ImageStackRadioButton->isChecked() ||
            ui->ControlSelector_VideoRadioButton->isChecked()))
    {
        this->_inputSettingsFile = ui->LoadConfigFileLineEdit->text().toLocal8Bit().constData();

        // Check if is the Stack of Images Mode
        if(ui->StackImageFileLineEdit->isEnabled()){
            this->_inputStackImageFile = ui->StackImageFileLineEdit->text().toLocal8Bit().constData();
        }
        this->_OutputFileURL = ui->OutputFileLineEdit->text().toLocal8Bit().constData();
        emit callCalibration();
    }
    else{
        QMessageBox formError;
        formError.setText("Form incomplete, please verify your informations");
        formError.exec();
    }
}

void PTAWindow::on_LoadConfigFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getOpenFileName(this, "Open a file", "../", "Configuration File (*.xml)");
    //this->_inputSettingsFile = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        this->ui->LoadConfigFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_StackImageFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getOpenFileName(this, "Open a file", "../", "Configuration File (*.xml)");
//    this->_inputStackImageFile = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        ui->StackImageFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_OutputFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getSaveFileName(this, "Save", "../untitled.xml", "(*.xml)");
//    this->_OutputFileURL = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        this->ui->OutputFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_ControlSelector_ImageStackRadioButton_clicked()
{
    ui->StackImageFileLineEdit->setEnabled(true);
    ui->StackImageFilePushButton->setEnabled(true);
}

void PTAWindow::on_ControlSelector_CameraRadioButton_clicked()
{
    ui->StackImageFileLineEdit->setEnabled(false);
    ui->StackImageFilePushButton->setEnabled(false);
}

void PTAWindow::on_ControlSelector_VideoRadioButton_clicked()
{
    ui->StackImageFileLineEdit->setEnabled(false);
    ui->StackImageFilePushButton->setEnabled(false);
}
