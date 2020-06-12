#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

#include <string>
#include <vector>

class Shader;
class Pipeline;
class IndexBuffer;
class VertexBuffer;

class Vertex;
struct GLFWwindow;

/**
 * Render device type to determine what API to use.
 */ 
struct RenderDeviceType
{
    enum Enum
    {
        NoRender,
        Default,
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
    virtual ~RenderDevice();

public:
    /** Current Render API type */
    RenderDeviceType::Enum renderType;

    /** Window for Rendering **/
    GLFWwindow* window;

public:
    /** Create window to render to. */
    virtual void CreateWindow(std::string windowName, bool fullscreen) {}

    /** Create a shader module */
    virtual Shader* CreateShader(std::vector<char> code) { return nullptr; }

    /** Create a pipeline */
    virtual Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) { return nullptr; }

    /** Create a vertex buffer */
    virtual VertexBuffer* CreateVertexBuffer() { return nullptr; }

    /** Create a index buffer */
    virtual IndexBuffer* CreateIndexBuffer() { return nullptr; }

    /** Starts the draw recording and re-records if needed */
    virtual void BeginRecordDraw(bool recreateCommandBuffers) {}

    /** End Draw */
    virtual void EndRecordDraw() {}

    /** Get if window is closing */
    virtual bool ShouldWindowClose();
};

RenderDevice* CreateRenderDevice(RenderDeviceType::Enum rdt);

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__