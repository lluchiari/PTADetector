#ifndef PTAWINDOW_H
#define PTAWINDOW_H

#include <QWidget>

namespace Ui {
class PTAWindow;
}

class PTAWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PTAWindow(QWidget *parent = 0);
    ~PTAWindow();

private:
    Ui::PTAWindow *ui;
};

#endif // PTAWINDOW_H
