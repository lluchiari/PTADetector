#include "../include/ptawindow.h"
#include "../include/PTADetector.h"
#include <common.h>

#include <QObject>
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // View
    PTAWindow w;
    w.show();

    // Controller
    PTADetector *detector = new PTADetector(&w);

    a.exec();
    delete detector;
}
