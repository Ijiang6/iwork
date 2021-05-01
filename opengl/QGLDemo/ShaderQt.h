#ifndef SHADERQT_H
#define SHADERQT_H

#include <QObject>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QString>
class ShaderQt : public QObject
{
    Q_OBJECT
public:
    explicit ShaderQt(const QString& vertexSourcePath, const QString& fragmentSourcePath,QObject *parent = nullptr);
    QOpenGLShaderProgram shaderProgram;

    void use(){
      shaderProgram.bind();
    }

    void setMat4(const QString &name ,const QMatrix4x4 &value);
    void  setInt(const QString & name , const GLint &value);

signals:

};

#endif // SHADERQT_H
