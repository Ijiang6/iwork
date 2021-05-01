#ifndef LIGHTGLGLSLEXTRAFUN_H
#define LIGHTGLGLSLEXTRAFUN_H

#include <QOpenGLWidget>
#include<QOpenGLExtraFunctions>
class LightGLGLSLExtraFun : public QOpenGLWidget ,public QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit LightGLGLSLExtraFun(QWidget *parent = nullptr);
    void drawCoord();
void paintGL() override;
void initializeGL() override;
void resizeGL(int w, int h) override; 

private:
unsigned int VBO;

};

#endif // LIGHTGLGLSLEXTRAFUN_H
