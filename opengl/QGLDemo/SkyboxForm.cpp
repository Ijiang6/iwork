
#include "SkyboxForm.h"

#include "ui_SkyboxForm.h"
#include<vector>
#include<string>
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
#include<iostream>




SkyboxForm::SkyboxForm(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::SkyboxForm)
{
    ui->setupUi(this);
}

SkyboxForm::~SkyboxForm()
{
    delete ui;
}

void SkyboxForm::paintGL()
{

    glClearColor(0.1f,0.1f,0.1f,0.1f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader->use();

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view =camera->GetViewMatrix();
    glm::mat4 projection  = glm::perspective(glm::radians(camera->Zoom),(float)width()/height(),0.1f,100.0f);
    shader->setMat4("model",model);
    shader->setMat4("view",view);
    shader->setMat4("projection",projection);
    shader->setVec3("cameraPos",camera->Position);

    //cube
    glBindVertexArray(VAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP,cubemapTexture);

    glDrawArrays(GL_TRIANGLES,0,36);
    glBindVertexArray(0);

    //draw skybox
    glDepthFunc(GL_LEQUAL);
    skyboxShader->use();
    view  = glm::mat4(glm::mat3(camera->GetViewMatrix()));
    skyboxShader->setMat4("view",view);
    skyboxShader->setMat4("projection",projection);

    glBindVertexArray(skyboxVAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS); // set depth function back to default


}

void SkyboxForm::initializeGL()
{
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "GLEW initialization failed" << std::endl;
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return;
	}
    //初始化opengl 函数
     initializeOpenGLFunctions();
	
     glEnable(GL_DEPTH_TEST);

     // ------------------------------------------------------------------
        float cubeVertices[] = {
            // positions          // normals
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
             0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };
        float skyboxVertices[] = {
            // positions
            -1.0f,  1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f, -1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,

            -1.0f, -1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,

            -1.0f,  1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f,  1.0f,  1.0f,
             1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f,

            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f,  1.0f,
             1.0f, -1.0f,  1.0f
        };

        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER,VBO);
         glBufferData(GL_ARRAY_BUFFER,sizeof (cubeVertices),cubeVertices,GL_STATIC_DRAW);
         // 坐标数据
          glEnableVertexAttribArray(0);
         glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(float), (void*)0);

         //法线数据
         glEnableVertexAttribArray(1);
         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

         // skybox VAO

         glGenVertexArrays(1, &skyboxVAO);
         glGenBuffers(1, &skyboxVBO);
         glBindVertexArray(skyboxVAO);
         glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
         glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
         glEnableVertexAttribArray(0);
         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

//          cubeTexture = loadTexture(std::string("./skybox/container.jpg").c_str());
         std::vector<std::string> vCubeFaces = {
             "./skybox/right.jpg",
             "./skybox/left.jpg",
             "./skybox/top.jpg",
             "./skybox/bottom.jpg",
             "./skybox/front.jpg",
             "./skybox/back.jpg"};
     cubemapTexture = loadCubemap(vCubeFaces);

	 shader = new Shader("./skybox/cubemaps_vs.txt", "./skybox/cubemaps_fs.txt");
	 skyboxShader = new Shader("./skybox/skybox_vs.txt", "./skybox/skybox_fs.txt");
	 camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
     shader->use();
     shader->setInt("skybox", 0);

     skyboxShader->use();
     skyboxShader->setInt("skybox", 0);


}

void SkyboxForm::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

unsigned int SkyboxForm::loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1,&textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP,textureID);

    int width, height,nrComponents;

    for (int index =0; index < faces.size(); ++index)
    {
        unsigned char *data = stbi_load(faces[index].c_str(),&width,&height,&nrComponents,0);
        if(data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+index,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "load iamge error:"<< faces[index]<<std::endl;
        }

    }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return textureID;
}

unsigned int SkyboxForm::loadTexture(const char *path)
{
    unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
        if (data)
        {
            GLenum format;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Texture failed to load at path: " << path << std::endl;
            stbi_image_free(data);
        }

        return textureID;
}

void SkyboxForm::mouseMoveEvent(QMouseEvent *event)
{
    static bool firstMouse = true;

	static float lastX = (float)width() / 2.0;
	static float lastY = (float)height() / 2.0;
    float xpos = event->x();
    float ypos = event->y();
    if (firstMouse)
       {
           lastX = xpos;
           lastY = ypos;
           firstMouse = false;
       }

       float xoffset = xpos - lastX;
       float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

       lastX = xpos;
       lastY = ypos;

       camera->ProcessMouseMovement(xoffset, yoffset);
	   update();
       event->ignore();
}

void SkyboxForm::wheelEvent(QWheelEvent *event)
{
	QPoint numDegrees = event->angleDelta() / 20;
    camera->ProcessMouseScroll(numDegrees.ry());
	update();
    event->ignore();
}
