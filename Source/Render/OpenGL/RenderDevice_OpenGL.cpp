#include "RenderDevice_OpenGL.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>


#include "Log.h"

RenderDevice_OpenGL::RenderDevice_OpenGL()
{

}

RenderDevice_OpenGL::~RenderDevice_OpenGL()
{

}

void RenderDevice_OpenGL::Initalize()
{
    glfwInit();
}

void RenderDevice_OpenGL::Terminate()
{
    glfwTerminate();
}

void RenderDevice_OpenGL::CreateWindow()
{
    
// Create OpenGL window
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(vidmode->width, vidmode->height, "Chronos", monitor, nullptr);
    assert_msg(window == NULL, "Render Device - OpenGL: Could not create GLFW window!");

    glfwMakeContextCurrent(window);

// Initalize glad after context was made
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        assert_msg(false, "Render Device - OpenGL: Could not initalize GLAD!");
    }
}