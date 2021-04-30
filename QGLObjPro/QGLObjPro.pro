QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/openGL
INCLUDEPATH += $$PWD/openGL/glm/glm
INCLUDEPATH += $$PWD/openGL/glm
INCLUDEPATH += $$PWD/Assimp/include
CONFIG += c++11
SOURCES += \
    main.cpp \
    GLObjLoader.cpp \
    MainWindow.cpp

HEADERS += \
    GLObjLoader.h \
    SkyMesh.h \
    SkyboxCamera.h \
    SkyboxModel.h \
    MainWindow.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
    LIBS += -L$$quote("D:\Works\code\opengl\QGLDemo\openGL\libs") -lglew32
    LIBS += -L$$quote("D:\Works\code\opengl\QGLDemo\Assimp\libs\Debug") -lassimp-vc140-mt
