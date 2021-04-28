#include "TextureGLGLSLExtraFun.h"
#include<QDataStream>
#include<QByteArray>
#include<QBuffer>
TextureGLGLSLExtraFun::TextureGLGLSLExtraFun(QWidget *pwgt) :QOpenGLWidget(pwgt)
{

}

void TextureGLGLSLExtraFun::textureQt()
{

    texture = new QOpenGLTexture(QImage(":/imgs/container.jpg").mirrored(), QOpenGLTexture::GenerateMipMaps);
    if(! texture->isCreated())
    {
        printf("texture create error\n");
    }
    texture->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture->setMinificationFilter(QOpenGLTexture::Linear);//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    texture->setFormat(QOpenGLTexture::RGBFormat); //将纹理储存为rgb值

    texture2 = new QOpenGLTexture(QImage(":/imgs/awesomeface.png").mirrored(), QOpenGLTexture::GenerateMipMaps);
    if(! texture2->isCreated())
    {
        printf("texture create error\n");
    }
    texture2->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);// 等于glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture2->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    texture2->setMinificationFilter(QOpenGLTexture::Linear);//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture2->setMagnificationFilter(QOpenGLTexture::Linear);//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    texture2->setFormat(QOpenGLTexture::RGBFormat); //将纹理储存为rgb值


}

unsigned char* deepCopyImageData(QImage image){
 // QImage image("test.png"); // test image
  QByteArray bytes;
  QBuffer buffer(&bytes);
  buffer.open(QIODevice::WriteOnly);
  image.save(&buffer, "PNG");
  buffer.close();

  unsigned char *data = (unsigned char *) malloc(bytes.size());
  memcpy(data, reinterpret_cast<unsigned char *>(bytes.data()), bytes.size());
 // size = bytes.size();
  return data;
}
void TextureGLGLSLExtraFun::textureGLSL()
{

    //创建纹理
    glGenTextures(1,&texture1);
    //指明纹理为2d图像
    glBindTexture(GL_TEXTURE_2D,texture1);
    //指定环绕方式
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_LINEAR);
    //指定纹理过滤参数
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    QImage img(":/imgs/awesomeface.png");
     int width = img.width();

     int height =img.height();
    if (img.bits())
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,img.bits());// 黑白
        glGenerateMipmap(GL_TEXTURE_2D);
    }
}

void TextureGLGLSLExtraFun::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
   glActiveTexture(GL_TEXTURE0);
    texture->bind();
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture1);
  //  texture2->bind();
    ourShader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void TextureGLGLSLExtraFun::initializeGL()
{
      initializeOpenGLFunctions();
    ourShader = new ShaderQt(":/shaders/texture.vs",":/shaders/texture.fs");
    //VAO，VBO数据部分
    float vertices[] = {
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right //注意新的数据，有纹理单元
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
       -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
       -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
    };

    GLuint indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    glBindVertexArray(VAO);


    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof (indices),indices,GL_STATIC_DRAW);
    // 坐标数据
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //  颜色
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
   // texture coord
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,2*sizeof (float),(void*)(3*sizeof (float)));
    glEnableVertexAttribArray(2);
    // texture
    textureQt();
    textureGLSL();
    //设置纹理单元编号
    ourShader->use();
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture1"), 0);
    ourShader->shaderProgram.setUniformValue(ourShader->shaderProgram.uniformLocation("texture2"), 1);
    glClearColor(0.2f,0.3f,0.3f,1.0f);

}

void TextureGLGLSLExtraFun::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}
