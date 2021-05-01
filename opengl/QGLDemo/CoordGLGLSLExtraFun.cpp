#include "CoordGLGLSLExtraFun.h"
#include<QDebug>
CoordGLGLSLExtraFun::CoordGLGLSLExtraFun(QWidget *parent) : QOpenGLWidget(parent)
{

}

void CoordGLGLSLExtraFun::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    texture1->bind();
    glActiveTexture(GL_TEXTURE1);
    texture2->bind();
    glBindVertexArray(VAO);

    QMatrix4x4 model;
    model.rotate((float)time.elapsed()/10, QVector3D(0.5f, 1.0f, 0.0f));
    ourShader->use();
    ourShader->setMat4("model", model);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    update();
}

void CoordGLGLSLExtraFun::initializeGL()
{
    initializeOpenGLFunctions();
    ourShader = new ShaderQt(":/shaders/CoordGLGLSLExtraFun.vs", ":/shaders/CoordGLGLSLExtraFun.fs");

    //VAO，VBO数据部分
    GLfloat vertices[] = {
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
       -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };

    GLuint indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

      glGenVertexArrays(1, &VAO);//两个参数，第一个为需要创建的缓存数量。第二个为用于存储单一ID或多个ID的GLuint变量或数组的地址
      glGenBuffers(1, &VBO);
      glGenBuffers(1, &EBO);

      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
    // color attribute
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
      glEnableVertexAttribArray(1);
    // texture coord attribute
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
      glEnableVertexAttribArray(2);

    //纹理
    //第一张箱子
    texture1 = new QOpenGLTexture(QImage(":/imgs/container.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
    if(!texture1->isCreated()){
        qDebug() << "Failed to load texture" << endl;
    }
    texture1->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture1->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture1->setMinificationFilter(QOpenGLTexture::Linear);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture1->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    //第二张笑脸
    texture2 = new QOpenGLTexture(QImage(":/imgs/awesomeface.png").mirrored(), QOpenGLTexture::GenerateMipMaps); //直接生成绑定一个2d纹理, 并生成多级纹理MipMaps
    if(!texture2->isCreated()){
        qDebug() << "Failed to load texture" << endl;
    }
    texture2->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture2->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture2->setMinificationFilter(QOpenGLTexture::Linear);   //等价于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture2->setMagnificationFilter(QOpenGLTexture::Linear);  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //设置纹理单元编号
    ourShader->use();
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture1"), 0);//等价于ourShader.setInt("texture1", 0) setInt函数，是Vries自写的函数，实际应用还是要先获取“texture1”的location，然后设值
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture2"), 1);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    QMatrix4x4 model , projection,view;
    model.rotate(-55.0f, QVector3D(1.0f, 0.0f, 0.0f));
    view.translate(QVector3D(0.0f, 0.0f, -3.0f));
    projection.perspective(45.0f, (GLfloat)width()/(GLfloat)height(), 0.1f, 100.0f);
    //开启计时器，返回毫秒
    time.start();
    ourShader->use();
    ourShader->setMat4("model", model);
    ourShader->setMat4("view", view);
    ourShader->setMat4("projection", projection);
}

void CoordGLGLSLExtraFun::resizeGL(int w, int h)
{
  glViewport(0,0,w,h);
}
