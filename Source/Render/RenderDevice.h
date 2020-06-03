#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

class Shader;
class Pipeline;
class IndexBuffer;
class VertexBuffer;

struct RenderDeviceType
{
    enum Enum
    {
        NoRender,
        OpenGL,
        Vulkan
    };
};

class RenderDevice
{

public:
    RenderDevice();
    ~RenderDevice();

public:
    RenderDeviceType::Enum renderType;

public:
    virtual Shader* CreateShader() {}
    virtual Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) {}
    virtual IndexBuffer* CreateIndexBuffer() {}
    virtual VertexBuffer* CreateVertexBuffer() {}

};

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__