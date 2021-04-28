#ifndef TRIANGLEGLQT_H
#define TRIANGLEGLQT_H

#include <QOpenGLWidget>
#include<QOpenGLFunctions>
#include<QOpenGLShaderProgram>

class TriangleGLQt : public QOpenGLWidget ,public QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit TriangleGLQt(QWidget *parent = nullptr);
     ~TriangleGLQt();
     void paintGL() override;
     void initializeGL() override;
     void resizeGL(int w, int h) override;
signals:

private:
     QOpenGLShaderProgram shaderProgram;
     QVector<QVector3D>vertices;
};

#endif // TRIANGLEGLQT_H
