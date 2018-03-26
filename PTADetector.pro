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
        source/mainwindow.cpp \
        source/PTADetector.cpp \
        source/filter/CannyFilter.cpp \
        source/calibration/Calibration.cpp \
        source/calibration/Settings.cpp

HEADERS += \
        include/mainwindow.h\
        include/PTADetector.h\
        include/calibration/Calibration.h\
        include/calibration/Settings.h\
        include/filter/CannyFilter.h

FORMS += \
        mainwindow.ui

DESTDIR = bin

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341d

#win64:CONFIG(release, debug|release): LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341
#/else:win64:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341d

LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341
LIBS += -L$$PWD/../../OpenCV/opencv/build/x64/vc15/lib/ -lopencv_world341d


INCLUDEPATH += $$PWD/../../OpenCV/opencv/build/x64/vc15 c:/Users/Lluchiari/Documents/OpenCV/opencv/build/include
DEPENDPATH += $$PWD/../../OpenCV/opencv/build/x64/vc15 c:/Users/Lluchiari/Documents/OpenCV/opencv/build/include

DISTFILES += \
    images/results/Complex3/bilateralFilter0.png \
    images/results/Complex3/bilateralFilter10.png \
    images/results/Complex3/bilateralFilter20.png \
    images/results/Complex3/bilateralFilter30.png \
    images/results/Complex3/bilateralFilter40.png \
    images/results/Complex3/bilateralFilter50.png \
    images/results/Complex3/bilateralFilter60.png \
    images/results/Complex3/bilateralFilter70.png \
    images/results/Complex3/bilateralFilter80.png \
    images/results/Complex3/bilateralFilter90.png \
    images/results/Complex3/gaussianBlur0.png \
    images/results/Complex3/gaussianBlur10.png \
    images/results/Complex3/gaussianBlur20.png \
    images/results/Complex3/gaussianBlur30.png \
    images/results/Complex3/gaussianBlur40.png \
    images/results/Complex3/gaussianBlur50.png \
    images/results/Complex3/gaussianBlur60.png \
    images/results/Complex3/gaussianBlur70.png \
    images/results/Complex3/gaussianBlur80.png \
    images/results/Complex3/gaussianBlur90.png \
    images/shapes/Complex3.png \
    images/shapes/Simple1.png \
    images/shapes/Simple2.png \
    images/shapes/Simple3.png
