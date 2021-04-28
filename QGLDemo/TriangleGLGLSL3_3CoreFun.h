#ifndef TRIANGLEGLGLSL3_3COREFUN_H
#define TRIANGLEGLGLSL3_3COREFUN_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include<QOpenGLContext>
#include"ShaderQt.h"
class TriangleGLGLSL3_3CoreFun : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit TriangleGLGLSL3_3CoreFun(QWidget *parent = nullptr);
void paintGL() override;
void initializeGL() override;
void resizeGL(int w, int h) override;
signals:

private:
    QOpenGLFunctions_3_3_Core *core;
    ShaderQt *shader;
    unsigned int VAO,VBO;
};

#endif // TRIANGLEGLGLSL3_3COREFUN_H
