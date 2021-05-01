

#include"SkyboxCamera.h"
#include"SkyboxModel.h"
#include "GLObjLoader.h"
GLObjLoader::GLObjLoader(QWidget *parent):
 QOpenGLWidget(parent)
{

}

void GLObjLoader::paintGL()
{
    // render
    // ------
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // don't forget to enable shader before setting uniforms
    shader->use();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)width() / (float)height(), 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(0.1f, 0.1f, 0.1f));	// it's a bit too big for our scene, so scale it down
    shader->setMat4("model", model);
    objmodel->Draw(*shader);
	
}

void GLObjLoader::initializeGL()
{
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "GLEW initialization failed" << std::endl;
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        return;
    }

    //初始化opengl 函数
    initializeOpenGLFunctions();
    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------
    shader = new Shader("D:/Works/code/QtProject/QGLObjPro/skybox/loadobj_vs.txt", "D:/Works/code/QtProject/QGLObjPro/skybox/loadobj_fs.txt");

    // load models
    // -----------
    objmodel = new Model(std::string("D:/Works/code/opengl/nanosuit_reflection/nanosuit.obj"));
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void GLObjLoader::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void GLObjLoader::mouseMoveEvent(QMouseEvent *event)
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

void GLObjLoader::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 20;
    camera->ProcessMouseScroll(numDegrees.ry());
    update();
    event->ignore();
}
