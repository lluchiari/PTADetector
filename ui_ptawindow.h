/********************************************************************************
** Form generated from reading UI file 'ptawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PTAWINDOW_H
#define UI_PTAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PTAWindow
{
public:

    void setupUi(QWidget *PTAWindow)
    {
        if (PTAWindow->objectName().isEmpty())
            PTAWindow->setObjectName(QStringLiteral("PTAWindow"));
        PTAWindow->resize(400, 300);

        retranslateUi(PTAWindow);

        QMetaObject::connectSlotsByName(PTAWindow);
    } // setupUi

    void retranslateUi(QWidget *PTAWindow)
    {
        PTAWindow->setWindowTitle(QApplication::translate("PTAWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PTAWindow: public Ui_PTAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTAWINDOW_H
