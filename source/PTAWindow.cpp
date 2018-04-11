#include "../include/PTAWindow.h"
#include "ui_ptawindow.h"

PTAWindow::PTAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTAWindow)
{
    ui->setupUi(this);

    // Configuring some user defaults
    ui->CameraIDSpinBox->setMaximum(MAX_CAM_QTY);
    ui->CameraIDSpinBox->setMinimum(0);
    ui->CameraIDSpinBox->setValue(0);
    ui->CameraStackedWidget->setCurrentWidget(ui->StackImageFileWidget);
}

PTAWindow::~PTAWindow()
{
    delete ui;
}



QString endHtml = "</font><br>";

void PTAWindow::writeLog(string text, int color){
    if(!text.empty()){
        QString _text = QString::fromStdString(text);
        QString startHtml = "<font color=";
        QString sizeHtml = "size=\"1\" ";
        QString endHtml = "</font><br>";

        // Visible Log Part
        if(color>0){
            switch (color) {
            case 1:
                _text = startHtml + QString("\"Red\" ") + sizeHtml + QString(">") + _text;
                break;
            case 2:
                _text = startHtml + QString("\"Green\" ") + sizeHtml + QString(">") + _text;
                break;
            case 3:
                _text = startHtml + QString("\"Blue\" ") + sizeHtml + QString(">") + _text;
                break;
            }
            _text += endHtml;
            ui->Log->insertHtml(_text);
        }
        else{
            _text = startHtml + QString("\"Black\" ") + sizeHtml + QString(">") + _text + endHtml;
            ui->Log->insertHtml(_text);
        }
    }
}

void PTAWindow::on_ConfirmPushButton_clicked()
{
    // Check if the Input and Output file Location is filled properly
    if(!ui->LoadConfigFileLineEdit->text().isEmpty() && !ui->OutputFileLineEdit->text().isEmpty())
    {
        // CAMERA Mode
        if(ui->ControlSelector_CameraRadioButton->isChecked()){
            this->_inputSettingsFile = ui->LoadConfigFileLineEdit->text().toLocal8Bit().constData();
            this->_inputStackImageFile = ui->CameraIDSpinBox->text().toLocal8Bit().constData();
            this->_OutputFileURL = ui->OutputFileLineEdit->text().toLocal8Bit().constData();
            emit callCalibration();
        }
        // IMAGE STACK Mode
        else if(ui->ControlSelector_ImageStackRadioButton->isChecked() && !ui->StackImageFileLineEdit->text().isEmpty()){
            this->_inputSettingsFile = ui->LoadConfigFileLineEdit->text().toLocal8Bit().constData();
            this->_inputStackImageFile = ui->StackImageFileLineEdit->text().toLocal8Bit().constData();
            this->_OutputFileURL = ui->OutputFileLineEdit->text().toLocal8Bit().constData();
            emit callCalibration();
        }
        // VIDEO Mode
        else if(ui->ControlSelector_VideoRadioButton->isChecked()){
            this->_inputSettingsFile = ui->LoadConfigFileLineEdit->text().toLocal8Bit().constData();
            this->_OutputFileURL = ui->OutputFileLineEdit->text().toLocal8Bit().constData();
            emit callCalibration();
        }
        // No case --> Error
        else{
            QMessageBox formError;
            formError.setText("Form incomplete, please choose your mode.");
            formError.exec();
        }
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
    aux = QFileDialog::getOpenFileName(this, "Open Configuration File", "../", "Configuration File (*.xml)");
    //this->_inputSettingsFile = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        this->ui->LoadConfigFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_StackImageFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getOpenFileName(this, "Open Stack Image File", "../", "Configuration File (*.xml)");
//    this->_inputStackImageFile = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        ui->StackImageFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_OutputFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getSaveFileName(this, "Save Calibration File", "../untitled.xml", "(*.xml)");
//    this->_OutputFileURL = aux.toLocal8Bit().constData();
    if(aux.size() != 0){
        this->ui->OutputFileLineEdit->setText(aux);
    }
}

void PTAWindow::on_ControlSelector_ImageStackRadioButton_clicked()
{
    ui->CameraStackedWidget->setCurrentWidget(ui->StackImageFileWidget);
}

void PTAWindow::on_ControlSelector_CameraRadioButton_clicked()
{
    ui->CameraStackedWidget->setCurrentWidget(ui->CameraIDWidget);
}

void PTAWindow::on_ControlSelector_VideoRadioButton_clicked()
{
    ui->CameraStackedWidget->setCurrentWidget(ui->StackImageFileWidget);
}
