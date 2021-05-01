#include "DepthGLGLSLExtraFun.h"

DepthGLGLSLExtraFun::DepthGLGLSLExtraFun(QWidget *parent) : QOpenGLWidget(parent)
{

}

void DepthGLGLSLExtraFun::paintGL()
{

}

void DepthGLGLSLExtraFun::initializeGL()
{
    initializeOpenGLFunctions();


}

void DepthGLGLSLExtraFun::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}
