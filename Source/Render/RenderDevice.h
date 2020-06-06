#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

#include <string>

class Shader;
class Pipeline;
class IndexBuffer;
class VertexBuffer;

/**
 * Render device type to determine what API to use.
 */ 
struct RenderDeviceType
{
    enum Enum
    {
        NoRender,
        OpenGL,
        Vulkan
    };
};

/**
 * Render device to tell the API what to do.
 */ 
class RenderDevice
{

public:
    /** Constructor */ 
    RenderDevice();

    /** Destructor */
    ~RenderDevice();

public:
    /** Current Render API type */
    RenderDeviceType::Enum renderType;

public:
    /** Create window to render to. */
    virtual void CreateWindow(std::string windowName, bool fullscreen) {}

    /** Create a shader module */
    virtual Shader* CreateShader() {}

    /** Create a pipeline */
    virtual Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) {}

    /** Create a vertex buffer */
    virtual VertexBuffer* CreateVertexBuffer() {}

    /** Create a index buffer */
    virtual IndexBuffer* CreateIndexBuffer() {}

};

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__