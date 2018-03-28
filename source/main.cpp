#include "../include/ptawindow.h"
#include "../include/calibration/Calibration.h"

#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    int ERROR = 0;
    QApplication a(argc, argv);
    PTAWindow w;
    w.show();
//    Calibration *calibTest = new Calibration(&w);

//    // Check if the reading process is working correctlly
//    if(calibTest->readSettings() != 0) {
//        ERROR = 1;
//        cerr << "Error on input files!" << std::endl;
//    }
//    else{
//        // Make the calibration
//        if(DEBUG) {std::cout << "Calibration Starting" << std::endl;}
//        calibTest->calibrate();
//    }

//    //QString inputSettingsFile = QFileDialog::getOpenFileName(&w, "Open a file", "", "Configuration File (*.xml)");
//    //std::cout << inputSettingsFile.toUtf8().constData();

//    delete calibTest;
    return a.exec();
}
