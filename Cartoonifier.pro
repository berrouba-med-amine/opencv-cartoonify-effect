#-------------------------------------------------
#
# Project created by QtCreator 2013-08-25T10:56:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Cartoonifier
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    cartoon.cpp
HEADERS += \
    cartoon.h

INCLUDEPATH += C:\opencv2.3.1_mingw\include

LIBS += -LC:\opencv2.3.1_mingw\bin\
    -lopencv_core231 \
    -lopencv_highgui231 \
    -lopencv_imgproc231 \
    -lopencv_features2d231 \
    -lopencv_calib3d231 \
    -lopencv_objdetect231 \
    -lopencv_video231\
    -lopencv_ml231\
    -lopencv_legacy231\
    -lopencv_gpu231\
    -lopencv_flann231\





