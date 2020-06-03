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
    OpenGL_RenderDevice();
    ~OpenGL_RenderDevice();

public:
    Shader* CreateShader() override;
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;
    IndexBuffer* CreateIndexBuffer() override;
    VertexBuffer* CreateVertexBuffer() override;

};

#endif // __CHRONOS_RENDER_OPENGL_RENDERDEVICE_H__