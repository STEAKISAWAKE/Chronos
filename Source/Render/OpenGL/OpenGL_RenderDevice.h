#ifndef __CHRONOS_RENDER_OPENGL_RENDERDEVICE_H__
#define __CHRONOS_RENDER_OPENGL_RENDERDEVICE_H__

#include "RenderDevice.h"

class OpenGL_Shader;
class OpenGL_Pipeline;
class OpenGL_IndexBuffer;
class OpenGL_VertexBuffer;

class OpenGL_RenderDevice
    : public RenderDevice
{

public:
    OpenGL_RenderDevice(std::string winName);
    ~OpenGL_RenderDevice();

public:
    void CreateWindow(std::string windowName, bool fullscreen) override;
    Shader* CreateShader(std::vector<char> code) override;
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;
    VertexBuffer* CreateVertexBuffer() override;
    IndexBuffer* CreateIndexBuffer() override;

};

#endif // __CHRONOS_RENDER_OPENGL_RENDERDEVICE_H__