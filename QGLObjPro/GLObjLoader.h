#ifndef GLOBJLOADER_H
#define GLOBJLOADER_H

#include<QOpenGLWidget>
#include<QOpenGLExtraFunctions>
#include<QOpenGLTexture>
#include<QMouseEvent>
#include <QWheelEvent>
#include<QWidget>

class Shader;
class Model;
class Camera;
class GLObjLoader:public QOpenGLWidget ,public QOpenGLExtraFunctions
{
public:
    GLObjLoader(QWidget *parent);
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;

void mouseMoveEvent(QMouseEvent *event);
void wheelEvent(QWheelEvent *event);

private:

 Shader *shader;
 Model *objmodel;
 Camera *camera;
};


#endif // GLOBJLOADER_H
