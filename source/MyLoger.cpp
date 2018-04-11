#include "../include/MyLoger.h"

MyLoger::MyLoger()
{
    this->_isQt = false;
    //this->_fsGeral.open("../logs/geral.log", std::fstream::out | std::fstream::app);
}

MyLoger::MyLoger(PTAWindow *window, QObject *parent) : QObject(parent)
{
    this->_wid = window;
    this->_isQt = true;
    this->_fsGeral.open("$$PWD/logs/geral.txt");

    QObject::connect(this, SIGNAL(writeOnLog(string, int)), this->_wid, SLOT(writeLog(string, int)));
}

MyLoger::~MyLoger()
{
    this->_fsGeral.close();
}

void MyLoger::write(string text)
{
    emit writeOnLog(text, 0);
    //writeOnFile(text);
}

void MyLoger::write(string text, int color)
{
    emit writeOnLog(text, color);
    //writeOnFile(text);
}

bool MyLoger::writeOnFile(string text)
{
    if(this->_fsGeral.is_open())
    {
        cout << "Entrou" << endl;
        this->_fsGeral << text;
        std::cout << "File Write Operation Successfully Performed\n";
        return true;
    }
    std::cerr << "Error opening file\n";
    return false;
}
