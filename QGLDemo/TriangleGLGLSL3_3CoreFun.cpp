#include "TriangleGLGLSL3_3CoreFun.h"

TriangleGLGLSL3_3CoreFun::TriangleGLGLSL3_3CoreFun(QWidget *parent) : QOpenGLWidget(parent)
{
        core = nullptr;
}

void TriangleGLGLSL3_3CoreFun::paintGL()
{
    core ->glClearColor(0.2f,0.3f,0.3f,1.0f);
    core->glClear(GL_COLOR_BUFFER_BIT );
    shader->use();
    core->glBindVertexArray(VAO);
    core->glDrawArrays(GL_TRIANGLES,0,3);
}

void TriangleGLGLSL3_3CoreFun::initializeGL()
{
    // shader
    core =  QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();

    shader = new ShaderQt(":/shaders/TriangleGLGLSL3_3CoreFun.vs",":/shaders/TriangleGLGLSL3_3CoreFun.fs");
    float  vertices[] = {
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top
    };

    core->glGenVertexArrays(1,&VAO);
    core->glGenBuffers(1,&VBO);
    core->glBindVertexArray(VAO);
    core->glBindBuffer(GL_ARRAY_BUFFER,VBO);

    core->glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);
    core->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void *)0);
    core->glEnableVertexAttribArray(0);

    core->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void *)(3*sizeof (float)));
    core->glEnableVertexAttribArray(1);

    core->glClearColor(0.2f,0.3f,0.3f,1.0f);
}

void TriangleGLGLSL3_3CoreFun::resizeGL(int w, int h)
{
    core->glViewport(0,0,w,h);
}
