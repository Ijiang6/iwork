#ifndef CAMERAGLGLSLEXTRAFUN_H
#define CAMERAGLGLSLEXTRAFUN_H

#include <QOpenGLWidget>
#include<QOpenGLExtraFunctions>
#include<QOpenGLTexture>
#include<QTime>
#include"Shader.h"
class CameraGLGLSLExtraFun : public QOpenGLWidget,public QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit CameraGLGLSLExtraFun(QWidget *parent = nullptr);

    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;

    Shader *ourShader;
    QOpenGLTexture *texture1;
    QOpenGLTexture *texture2;
    QTime time; //增添QTime对象，替代glfwGetTime()函数
    unsigned int VAO,VBO;
};

#endif // CAMERAGLGLSLEXTRAFUN_H
