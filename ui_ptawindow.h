/********************************************************************************
** Form generated from reading UI file 'ptawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PTAWINDOW_H
#define UI_PTAWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PTAWindow
{
public:
    QGridLayout *gridLayout;
    QTextEdit *Log;
    QTabWidget *tabWidget;
    QWidget *Calibration;
    QWidget *Aquisition;

    void setupUi(QWidget *PTAWindow)
    {
        if (PTAWindow->objectName().isEmpty())
            PTAWindow->setObjectName(QStringLiteral("PTAWindow"));
        PTAWindow->resize(496, 277);
        gridLayout = new QGridLayout(PTAWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 3, 9, 9);
        Log = new QTextEdit(PTAWindow);
        Log->setObjectName(QStringLiteral("Log"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(Log->sizePolicy().hasHeightForWidth());
        Log->setSizePolicy(sizePolicy);
        Log->setSizeIncrement(QSize(0, 0));
        Log->setBaseSize(QSize(0, 1));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        Log->setFont(font);
        Log->setLocale(QLocale(QLocale::English, QLocale::Canada));
        Log->setReadOnly(true);

        gridLayout->addWidget(Log, 1, 0, 1, 1);

        tabWidget = new QTabWidget(PTAWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setBaseSize(QSize(0, 10));
        Calibration = new QWidget();
        Calibration->setObjectName(QStringLiteral("Calibration"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Calibration->sizePolicy().hasHeightForWidth());
        Calibration->setSizePolicy(sizePolicy2);
        tabWidget->addTab(Calibration, QString());
        Aquisition = new QWidget();
        Aquisition->setObjectName(QStringLiteral("Aquisition"));
        tabWidget->addTab(Aquisition, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(PTAWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PTAWindow);
    } // setupUi

    void retranslateUi(QWidget *PTAWindow)
    {
        PTAWindow->setWindowTitle(QApplication::translate("PTAWindow", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Calibration), QApplication::translate("PTAWindow", "Calibration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Aquisition), QApplication::translate("PTAWindow", "Aquisition", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PTAWindow: public Ui_PTAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTAWINDOW_H
