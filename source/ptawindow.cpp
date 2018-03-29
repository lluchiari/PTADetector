#include "../include/ptawindow.h"
#include "ui_ptawindow.h"

PTAWindow::PTAWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PTAWindow)
{
    ui->setupUi(this);
    //ui->ControlSelector_CameraRadioButton->setEnabled(true);
}

PTAWindow::~PTAWindow()
{
    delete ui;
}

void PTAWindow::on_ConfirmPushButton_clicked()
{
    if(!this->ui->LoadConfigFileLineEdit->text().isEmpty() && !this->ui->StackImageFileLineEdit->text().isEmpty()
            && (ui->ControlSelector_CameraRadioButton->isOn() ||
            ui->ControlSelector_ImageStackRadioButton->isOn() ||
            ui->ControlSelector_VideoRadioButton->isOn())) {
        cout << "Execute Calibration!" << endl;
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
    this->_inputSettingsFile = aux.toLocal8Bit().constData();
    this->ui->LoadConfigFileLineEdit->setText(aux);
}

void PTAWindow::on_StackImageFilePushButton_clicked()
{
    QString aux;
    aux = QFileDialog::getOpenFileName(this, "Open a file", "../", "Configuration File (*.xml)");
    this->_inputStackImageFile = aux.toLocal8Bit().constData();
    this->ui->StackImageFileLineEdit->setText(aux);

}
