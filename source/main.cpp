#include "../include/PTAWindow.h"
#include "../include/PTADetector.h"
#include "../include/Myloger.h"
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

    // Start Log System
    MyLoger *logsys = new MyLoger(&w);

    // Controller
    PTADetector *detector = new PTADetector(&w, logsys);

    a.exec();
    delete detector;
}
