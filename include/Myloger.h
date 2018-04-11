#ifndef __MYLOGER_H__
#define __MYLOGER_H__

//Qt Libs
#include <QObject>

// STL Libs
#include <iostream>
#include <fstream>
#include <string>

//Internal Lib
#include "./PTAWindow.h"
#include <common.h>

using namespace std;

class MyLoger : public QObject
{
    Q_OBJECT

public:
    MyLoger();
    MyLoger(PTAWindow *, QObject *parent=0);   // For QT interface
    ~MyLoger();

public:
    void write(string);
    void write(string, int);
    bool writeOnFile(string);
    string read();

signals:
    void writeOnLog(string, int);

private:
    PTAWindow *_wid;
    fstream _fsGeral;
    bool _isQt;
};

#endif // MYLOGER_H
