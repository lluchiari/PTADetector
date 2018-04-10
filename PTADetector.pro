#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T18:45:48
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PTADetector
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        source/main.cpp \
        source/PTADetector.cpp \
        source/filter/CannyFilter.cpp \
        source/calibration/Calibration.cpp \
        source/calibration/Settings.cpp \
        source/ptawindow.cpp

HEADERS += \        
        include/PTADetector.h\
        include/calibration/Calibration.h\
        include/calibration/Settings.h\
        include/filter/CannyFilter.h\
        include/utils/common.h \
        include/ptawindow.h

FORMS += \
        forms/ptawindow.ui

DESTDIR = build/bin


LIBS += -L$(OPENCV_STATIC_DIR)/build/x64/vc15/lib/ -lopencv_world341
LIBS += -L$(OPENCV_STATIC_DIR)/build/x64/vc15/lib/ -lopencv_world341d

#Ideas
#unix:INCLUDEPATH += "/home/user/extra headers"

INCLUDEPATH += $(OPENCV_STATIC_DIR)/build/x64/vc15 $(OPENCV_STATIC_DIR)/build/include
INCLUDEPATH += $$PWD/config
INCLUDEPATH += $$PWD/include/utils

DISTFILES += \
    $$PWD/config/* \
    $$PWD/images/CameraCalibration/* \
    $$PWD/images/results/* \
    $$PWD/images/shapes/*
