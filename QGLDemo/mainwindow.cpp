
#include "mainwindow.h"
#include <bitset>         // std::bitset
//#include"TriangleGLQt.h"
//#include"TriangleGLGLSL3_3CoreFun.h"
//#include"TextureGLGLSLExtraFun.h"
//#include"CoordGLGLSLExtraFun.h"
//#include"CameraGLGLSLExtraFun.h"
//#include"DepthGLGLSLExtraFun.h"
#include"SkyboxForm.h"


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    m_layout = new QVBoxLayout(this);

    setLayout(m_layout);
    QWidget* m_painting =new SkyboxForm(this);//TextureGLGLSLExtraFun(this);
    m_layout->addWidget(m_painting);

}

MainWindow::~MainWindow()
{

}


