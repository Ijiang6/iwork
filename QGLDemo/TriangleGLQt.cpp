#include "TriangleGLQt.h"
const char *vertexShaderSource =
        "#version 330 core\n"
        "layout(location = 0) in vec3 aPos;\n"
        "void main(){\n"
        "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
        "}\n\0";
const char *fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main(){\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
TriangleGLQt::TriangleGLQt(QWidget *parent) : QOpenGLWidget(parent)
{

}

TriangleGLQt::~TriangleGLQt()
{

}

void TriangleGLQt::paintGL()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    shaderProgram.bindAttributeLocation("aPos", 0);// 等于glUseProgram(shaderProgram)
    shaderProgram.enableAttributeArray(0);
    shaderProgram.setAttributeArray(0, vertices.data());
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

}

void TriangleGLQt::initializeGL()
{
    //init functions beauase import QOpenglFunctions
    this->initializeOpenGLFunctions();
    QOpenGLShader vertexsd (QOpenGLShader::Vertex);

    bool bok=vertexsd.compileSourceCode(vertexShaderSource);
    if(!bok)
    {
        printf("vertex shader error!\n");
        return;
    }

    QOpenGLShader fragsd(QOpenGLShader::Fragment);

    bok = fragsd.compileSourceCode(fragmentShaderSource);
    if(!bok)
    {
        printf("fragment shader error!\n");
        return;
    }

    shaderProgram.addShader(&vertexsd);
    shaderProgram.addShader(&fragsd);

    bok = shaderProgram.link();

    if(!bok)
    {
        printf("shaderprogram link error \n");
    }
    shaderProgram.bind();


    //VAO，VBO数据部分
    vertices.append(QVector3D(-0.5, -0.5, 0.0));
    vertices.append(QVector3D(0.5, -0.5, 0.0));
    vertices.append(QVector3D(0.0, 0.5, 0.0));


}
void TriangleGLQt::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

