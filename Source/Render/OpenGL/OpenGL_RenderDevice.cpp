#include "OpenGL_RenderDevice.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

OpenGL_RenderDevice::OpenGL_RenderDevice()
{
    glfwInit();
}

OpenGL_RenderDevice::~OpenGL_RenderDevice()
{
    glfwTerminate();
}

void OpenGL_RenderDevice::CreateWindow(std::string windowName, bool fullscreen)
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);

    int monitorWidth = vidmode->width, monitorHeight = vidmode->height;

    if(fullscreen)
    {
        glfwCreateWindow(monitorWidth, monitorHeight, windowName.c_str(), monitor, nullptr);
    }
    else
    {
        glfwCreateWindow(monitorWidth, monitorHeight, windowName.c_str(), nullptr, nullptr);
    }
}

Shader* OpenGL_RenderDevice::CreateShader(std::vector<char> code)
{
    return nullptr;
}

Pipeline* OpenGL_RenderDevice::CreatePipeline(Shader* vertexShader, Shader* fragmentShader)
{
    return nullptr;
}

VertexBuffer* OpenGL_RenderDevice::CreateVertexBuffer()
{
    return nullptr;
}

IndexBuffer* OpenGL_RenderDevice::CreateIndexBuffer()
{
    return nullptr;
}
