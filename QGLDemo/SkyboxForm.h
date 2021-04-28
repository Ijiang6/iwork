#ifndef SKYBOXFORM_H
#define SKYBOXFORM_H

#include"SkyboxCamera.h"
#include<QOpenGLWidget>
#include<QOpenGLExtraFunctions>
#include<QOpenGLTexture>
#include<QMouseEvent>
#include <QWheelEvent>
namespace Ui {
class SkyboxForm;
}

class SkyboxForm :public QOpenGLWidget ,public QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    explicit SkyboxForm(QWidget *parent = nullptr);
    ~SkyboxForm();
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
unsigned int loadCubemap(std::vector<std::string> faces);
unsigned int loadTexture(char const * path);
void mouseMoveEvent(QMouseEvent *event);
void wheelEvent(QWheelEvent *event);
private:
    Ui::SkyboxForm *ui;
    unsigned int VAO ,VBO;
    unsigned int skyboxVAO, skyboxVBO;
     unsigned int cubemapTexture;
     unsigned int cubeTexture;
     Shader *shader;
     Shader *skyboxShader;
     Camera *camera;

};

#endif // SKYBOXFORM_H
