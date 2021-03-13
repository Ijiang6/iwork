#-------------------------------------------------
#
# Project created by QtCreator 2020-06-17T12:00:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IPhotoshop
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

INCLUDEPATH += $$PWD\opencv \
                $$PWD\scene
SOURCES += \
        main.cpp \
        MainWindow.cpp \
    SDockWidget.cpp \
    opencv/ImageRotationForm.cpp \
    opencv/ImageCroppingForm.cpp \
    scene/CustomGraphicsItem.cpp \
    scene/CustomGraphicsScene.cpp \
    scene/CustomGraphicsView.cpp \
    scene/WaterDrop.cpp \
    opencv/BrightnessContrastForm.cpp \
    CGlobal.cpp \
    opencv/OpencvConvertFun.cpp \
    opencv/WarpAffineForm.cpp

HEADERS += \
        MainWindow.h \
    SDockWidget.h \
    opencv/ImageRotationForm.h \
    opencv/ImageCroppingForm.h \
    scene/CustomGraphicsItem.h \
    scene/CustomGraphicsScene.h \
    scene/CustomGraphicsView.h \
    scene/WaterDrop.h \
    opencv/BrightnessContrastForm.h \
    CGlobal.h \
    opencv/OpencvConvertFun.h \
    opencv/WarpAffineForm.h

FORMS += \
    opencv/ImageRotationForm.ui \
    opencv/ImageCroppingForm.ui \
    opencv/BrightnessContrastForm.ui \
    MainWindow.ui \
    opencv/WarpAffineForm.ui
include($$PWD/opencvCof.pri)

RESOURCES += \
    source.qrc
