#include "ShaderQt.h"

ShaderQt::ShaderQt(const QString& vertexSourcePath, const QString& fragmentSourcePath,QObject *parent) : QObject(parent)
{
    QOpenGLShader vertexShader(QOpenGLShader::Vertex);
    bool bOK = vertexShader.compileSourceFile(vertexSourcePath);
    if(!bOK)
    {
        printf("vertext shader error\n");
        return;
    }
    QOpenGLShader fragmentShader(QOpenGLShader::Fragment);

    bOK = fragmentShader.compileSourceFile(fragmentSourcePath);
    if(!bOK)
    {
        printf("fragement shader error\n");
        return ;
    }
    shaderProgram.addShader(&vertexShader);
    shaderProgram.addShader(&fragmentShader);

    bOK = shaderProgram.link();
    if(!bOK)
    {
        printf("link error\n");
        return ;
    }
}

void ShaderQt::setMat4(const QString &name, const QMatrix4x4 &value)
{
    GLuint loc = shaderProgram.uniformLocation(name);
    shaderProgram.setUniformValue(loc,value);
}

void ShaderQt::setInt(const QString &name, const GLint &value)
{
    GLuint loc = shaderProgram.uniformLocation(name);
    shaderProgram.setUniformValue(loc, value);
}
