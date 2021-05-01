#include "LightGLGLSLExtraFun.h"

LightGLGLSLExtraFun::LightGLGLSLExtraFun(QWidget *parent) : QOpenGLWidget(parent)
{
    
}

void LightGLGLSLExtraFun::drawCoord()
{
    float step = 0.5;
    
    float vertexs[]=
    {
        0.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,0.0f,1.0f
    };
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (vertexs),vertexs,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void LightGLGLSLExtraFun::paintGL()
{
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINES, 0, 6);

}

void LightGLGLSLExtraFun::initializeGL()
{
    initializeOpenGLFunctions();
    drawCoord();
}

void LightGLGLSLExtraFun::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}
