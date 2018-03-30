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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PTAWindow
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Calibration;
    QHBoxLayout *horizontalLayout;
    QWidget *LoadCalibrationFile;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *ControlPanel;
    QVBoxLayout *verticalLayout_3;
    QWidget *ControlSelector;
    QVBoxLayout *verticalLayout;
    QLabel *ControlSelectorLabel;
    QWidget *ControlSelectorWidget;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *ControlSelector_ImageStackRadioButton;
    QRadioButton *ControlSelector_CameraRadioButton;
    QRadioButton *ControlSelector_VideoRadioButton;
    QVBoxLayout *LoadConfigFileLayout;
    QLabel *LoadConfigFileLabel;
    QWidget *LoadConfigFileWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *LoadConfigFileLineEdit;
    QPushButton *LoadConfigFilePushButton;
    QVBoxLayout *StackImageFileLayout;
    QLabel *StackImageFileLabel;
    QWidget *StackImageFileWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *StackImageFileLineEdit;
    QPushButton *StackImageFilePushButton;
    QVBoxLayout *OutputFileLayout;
    QLabel *OutputFileLabel;
    QWidget *OutputFileWidget;
    QHBoxLayout *horizontalLayout_21;
    QLineEdit *OutputFileLineEdit;
    QPushButton *OutputFilePushButton;
    QWidget *ConfirmWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ConfirmPushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *Aquisition;
    QTextEdit *Log;

    void setupUi(QWidget *PTAWindow)
    {
        if (PTAWindow->objectName().isEmpty())
            PTAWindow->setObjectName(QStringLiteral("PTAWindow"));
        PTAWindow->resize(677, 481);
        gridLayout = new QGridLayout(PTAWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 3, 9, 9);
        tabWidget = new QTabWidget(PTAWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setBaseSize(QSize(0, 10));
        Calibration = new QWidget();
        Calibration->setObjectName(QStringLiteral("Calibration"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Calibration->sizePolicy().hasHeightForWidth());
        Calibration->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(Calibration);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LoadCalibrationFile = new QWidget(Calibration);
        LoadCalibrationFile->setObjectName(QStringLiteral("LoadCalibrationFile"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LoadCalibrationFile->sizePolicy().hasHeightForWidth());
        LoadCalibrationFile->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(LoadCalibrationFile);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(LoadCalibrationFile);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);


        horizontalLayout->addWidget(LoadCalibrationFile);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ControlPanel = new QWidget(Calibration);
        ControlPanel->setObjectName(QStringLiteral("ControlPanel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(8);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ControlPanel->sizePolicy().hasHeightForWidth());
        ControlPanel->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(ControlPanel);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ControlSelector = new QWidget(ControlPanel);
        ControlSelector->setObjectName(QStringLiteral("ControlSelector"));
        verticalLayout = new QVBoxLayout(ControlSelector);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ControlSelectorLabel = new QLabel(ControlSelector);
        ControlSelectorLabel->setObjectName(QStringLiteral("ControlSelectorLabel"));

        verticalLayout->addWidget(ControlSelectorLabel);

        ControlSelectorWidget = new QWidget(ControlSelector);
        ControlSelectorWidget->setObjectName(QStringLiteral("ControlSelectorWidget"));
        horizontalLayout_5 = new QHBoxLayout(ControlSelectorWidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ControlSelector_ImageStackRadioButton = new QRadioButton(ControlSelectorWidget);
        ControlSelector_ImageStackRadioButton->setObjectName(QStringLiteral("ControlSelector_ImageStackRadioButton"));

        horizontalLayout_5->addWidget(ControlSelector_ImageStackRadioButton);

        ControlSelector_CameraRadioButton = new QRadioButton(ControlSelectorWidget);
        ControlSelector_CameraRadioButton->setObjectName(QStringLiteral("ControlSelector_CameraRadioButton"));

        horizontalLayout_5->addWidget(ControlSelector_CameraRadioButton);

        ControlSelector_VideoRadioButton = new QRadioButton(ControlSelectorWidget);
        ControlSelector_VideoRadioButton->setObjectName(QStringLiteral("ControlSelector_VideoRadioButton"));

        horizontalLayout_5->addWidget(ControlSelector_VideoRadioButton);


        verticalLayout->addWidget(ControlSelectorWidget);


        verticalLayout_3->addWidget(ControlSelector);

        LoadConfigFileLayout = new QVBoxLayout();
        LoadConfigFileLayout->setObjectName(QStringLiteral("LoadConfigFileLayout"));
        LoadConfigFileLabel = new QLabel(ControlPanel);
        LoadConfigFileLabel->setObjectName(QStringLiteral("LoadConfigFileLabel"));

        LoadConfigFileLayout->addWidget(LoadConfigFileLabel);

        LoadConfigFileWidget = new QWidget(ControlPanel);
        LoadConfigFileWidget->setObjectName(QStringLiteral("LoadConfigFileWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(LoadConfigFileWidget->sizePolicy().hasHeightForWidth());
        LoadConfigFileWidget->setSizePolicy(sizePolicy4);
        horizontalLayout_4 = new QHBoxLayout(LoadConfigFileWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LoadConfigFileLineEdit = new QLineEdit(LoadConfigFileWidget);
        LoadConfigFileLineEdit->setObjectName(QStringLiteral("LoadConfigFileLineEdit"));

        horizontalLayout_4->addWidget(LoadConfigFileLineEdit);

        LoadConfigFilePushButton = new QPushButton(LoadConfigFileWidget);
        LoadConfigFilePushButton->setObjectName(QStringLiteral("LoadConfigFilePushButton"));

        horizontalLayout_4->addWidget(LoadConfigFilePushButton);


        LoadConfigFileLayout->addWidget(LoadConfigFileWidget);


        verticalLayout_3->addLayout(LoadConfigFileLayout);

        StackImageFileLayout = new QVBoxLayout();
        StackImageFileLayout->setObjectName(QStringLiteral("StackImageFileLayout"));
        StackImageFileLabel = new QLabel(ControlPanel);
        StackImageFileLabel->setObjectName(QStringLiteral("StackImageFileLabel"));

        StackImageFileLayout->addWidget(StackImageFileLabel);

        StackImageFileWidget = new QWidget(ControlPanel);
        StackImageFileWidget->setObjectName(QStringLiteral("StackImageFileWidget"));
        sizePolicy4.setHeightForWidth(StackImageFileWidget->sizePolicy().hasHeightForWidth());
        StackImageFileWidget->setSizePolicy(sizePolicy4);
        horizontalLayout_2 = new QHBoxLayout(StackImageFileWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        StackImageFileLineEdit = new QLineEdit(StackImageFileWidget);
        StackImageFileLineEdit->setObjectName(QStringLiteral("StackImageFileLineEdit"));

        horizontalLayout_2->addWidget(StackImageFileLineEdit);

        StackImageFilePushButton = new QPushButton(StackImageFileWidget);
        StackImageFilePushButton->setObjectName(QStringLiteral("StackImageFilePushButton"));

        horizontalLayout_2->addWidget(StackImageFilePushButton);


        StackImageFileLayout->addWidget(StackImageFileWidget);


        verticalLayout_3->addLayout(StackImageFileLayout);

        OutputFileLayout = new QVBoxLayout();
        OutputFileLayout->setObjectName(QStringLiteral("OutputFileLayout"));
        OutputFileLabel = new QLabel(ControlPanel);
        OutputFileLabel->setObjectName(QStringLiteral("OutputFileLabel"));

        OutputFileLayout->addWidget(OutputFileLabel);

        OutputFileWidget = new QWidget(ControlPanel);
        OutputFileWidget->setObjectName(QStringLiteral("OutputFileWidget"));
        sizePolicy4.setHeightForWidth(OutputFileWidget->sizePolicy().hasHeightForWidth());
        OutputFileWidget->setSizePolicy(sizePolicy4);
        horizontalLayout_21 = new QHBoxLayout(OutputFileWidget);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        OutputFileLineEdit = new QLineEdit(OutputFileWidget);
        OutputFileLineEdit->setObjectName(QStringLiteral("OutputFileLineEdit"));

        horizontalLayout_21->addWidget(OutputFileLineEdit);

        OutputFilePushButton = new QPushButton(OutputFileWidget);
        OutputFilePushButton->setObjectName(QStringLiteral("OutputFilePushButton"));

        horizontalLayout_21->addWidget(OutputFilePushButton);


        OutputFileLayout->addWidget(OutputFileWidget);


        verticalLayout_3->addLayout(OutputFileLayout);

        ConfirmWidget = new QWidget(ControlPanel);
        ConfirmWidget->setObjectName(QStringLiteral("ConfirmWidget"));
        horizontalLayout_3 = new QHBoxLayout(ConfirmWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ConfirmPushButton = new QPushButton(ConfirmWidget);
        ConfirmPushButton->setObjectName(QStringLiteral("ConfirmPushButton"));

        horizontalLayout_3->addWidget(ConfirmPushButton);


        verticalLayout_3->addWidget(ConfirmWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(ControlPanel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tabWidget->addTab(Calibration, QString());
        Aquisition = new QWidget();
        Aquisition->setObjectName(QStringLiteral("Aquisition"));
        tabWidget->addTab(Aquisition, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        Log = new QTextEdit(PTAWindow);
        Log->setObjectName(QStringLiteral("Log"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(2);
        sizePolicy5.setHeightForWidth(Log->sizePolicy().hasHeightForWidth());
        Log->setSizePolicy(sizePolicy5);
        Log->setSizeIncrement(QSize(0, 0));
        Log->setBaseSize(QSize(0, 1));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        Log->setFont(font);
        Log->setLocale(QLocale(QLocale::English, QLocale::Canada));
        Log->setReadOnly(true);

        gridLayout->addWidget(Log, 1, 0, 1, 1);

        QWidget::setTabOrder(tabWidget, ControlSelector_ImageStackRadioButton);
        QWidget::setTabOrder(ControlSelector_ImageStackRadioButton, ControlSelector_CameraRadioButton);
        QWidget::setTabOrder(ControlSelector_CameraRadioButton, ControlSelector_VideoRadioButton);
        QWidget::setTabOrder(ControlSelector_VideoRadioButton, LoadConfigFileLineEdit);
        QWidget::setTabOrder(LoadConfigFileLineEdit, LoadConfigFilePushButton);
        QWidget::setTabOrder(LoadConfigFilePushButton, OutputFileLineEdit);
        QWidget::setTabOrder(OutputFileLineEdit, OutputFilePushButton);
        QWidget::setTabOrder(OutputFilePushButton, ConfirmPushButton);
        QWidget::setTabOrder(ConfirmPushButton, Log);
        QWidget::setTabOrder(Log, pushButton);

        retranslateUi(PTAWindow);
        QObject::connect(LoadConfigFilePushButton, SIGNAL(clicked()), LoadConfigFileLineEdit, SLOT(copy()));
        QObject::connect(OutputFilePushButton, SIGNAL(clicked()), OutputFileLineEdit, SLOT(copy()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PTAWindow);
    } // setupUi

    void retranslateUi(QWidget *PTAWindow)
    {
        PTAWindow->setWindowTitle(QApplication::translate("PTAWindow", "PTA Vision Detector", nullptr));
        pushButton->setText(QApplication::translate("PTAWindow", "Camera Prevew", nullptr));
        ControlSelectorLabel->setText(QApplication::translate("PTAWindow", "Mode:", nullptr));
        ControlSelector_ImageStackRadioButton->setText(QApplication::translate("PTAWindow", "Image Stack", nullptr));
        ControlSelector_CameraRadioButton->setText(QApplication::translate("PTAWindow", "Camera", nullptr));
        ControlSelector_VideoRadioButton->setText(QApplication::translate("PTAWindow", "Video", nullptr));
        LoadConfigFileLabel->setText(QApplication::translate("PTAWindow", "Load Configuration File:", nullptr));
        LoadConfigFilePushButton->setText(QApplication::translate("PTAWindow", "Load", nullptr));
        StackImageFileLabel->setText(QApplication::translate("PTAWindow", "Load Stack Image File:", nullptr));
        StackImageFilePushButton->setText(QApplication::translate("PTAWindow", "Load", nullptr));
        OutputFileLabel->setText(QApplication::translate("PTAWindow", "Output File Location:", nullptr));
        OutputFilePushButton->setText(QApplication::translate("PTAWindow", "Load", nullptr));
        ConfirmPushButton->setText(QApplication::translate("PTAWindow", "Calibrate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Calibration), QApplication::translate("PTAWindow", "Calibration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Aquisition), QApplication::translate("PTAWindow", "Aquisition", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PTAWindow: public Ui_PTAWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PTAWINDOW_H
