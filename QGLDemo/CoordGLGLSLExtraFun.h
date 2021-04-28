#ifndef COORDGLGLSLEXTRAFUN_H
#define COORDGLGLSLEXTRAFUN_H

#include <QOpenGLWidget>
#include<QOpenGLExtraFunctions>
#include<QOpenGLTexture>
#include<QTime>
#include"ShaderQt.h"
class CoordGLGLSLExtraFun : public QOpenGLWidget ,public QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit CoordGLGLSLExtraFun(QWidget *parent = nullptr);

    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
private:

   ShaderQt * ourShader;
   unsigned int VAO,VBO, EBO;
   QOpenGLTexture *texture1;
   QOpenGLTexture *texture2;
    QTime time;
};

#endif // COORDGLGLSLEXTRAFUN_H
