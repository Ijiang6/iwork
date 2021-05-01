#ifndef TEXTUREGLGLSLEXTRAFUN_H
#define TEXTUREGLGLSLEXTRAFUN_H

#include<QOpenGLWidget>
#include<QOpenGLExtraFunctions>
#include<QOpenGLTexture>
#include"ShaderQt.h"
class TextureGLGLSLExtraFun :public QOpenGLWidget ,public QOpenGLExtraFunctions
{
public:
    TextureGLGLSLExtraFun(QWidget *pwgt = nullptr);
    void textureQt();
    void textureGLSL();
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
private:
    unsigned int VAO ,VBO ,EBO;
    unsigned int texture1;

    ShaderQt *ourShader;
   QOpenGLTexture *texture;//新添项
   QOpenGLTexture *texture2;//新添项
};

#endif // TEXTUREGLGLSLEXTRAFUN_H
