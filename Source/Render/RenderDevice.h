#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

#include <string>
#include <vector>
#include <functional>

class Shader;
class Pipeline;
class Vertex;
class IndexBuffer;
class VertexBuffer;

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
    /** Default Constructor */
    RenderDevice();

    /** Constructor */ 
    RenderDevice(std::function<void(RenderDevice*)> drawFunc, std::string winName);

    /** Destructor */
    virtual ~RenderDevice();

public:
    /** Current Render API type */
    RenderDeviceType::Enum renderType;

    /** Window for Rendering **/
    GLFWwindow* window;

public:
    /** Create window to render to. */
    virtual void CreateWin(std::string windowName, bool fullscreen) {}

    /** Create a shader module */
    virtual Shader* CreateShader(std::vector<char> code) { return nullptr; }

    /** Create a pipeline */
    virtual Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) { return nullptr; }

    /** Create a vertex buffer */
    virtual VertexBuffer* CreateVertexBuffer(std::vector<Vertex> Vertices) { return nullptr; }

    /** Create a index buffer */
    virtual IndexBuffer* CreateIndexBuffer(std::vector<uint32_t> Indices) { return nullptr; }

    /** Starts the draw recording and re-records if needed */
    virtual void BeginRecordDraw() {}

    /** End Draw */
    virtual void EndRecordDraw() {}

    /** Ready to draw (all pipelines and shaders must be created!) */
    virtual void DrawBuffers() {}

    /** Draw new frame to the screen */
    virtual void DrawFrame() {}

    /** Used to deactivate anything that is needed to before deconstruction. */
    virtual void DoneRendering() {}

    /** Sets draw function */
    virtual void SetDrawFunction(std::function<void(RenderDevice*)> drawFunc) { drawFunction = drawFunc; }

    /** Get if window is closing */
    virtual bool ShouldWindowClose();

public:
    std::string windowName;

    // Draw function pointer
    std::function<void(RenderDevice*)> drawFunction;

    bool createdDrawBuffers = false;

};

RenderDevice* CreateRenderDevice(std::function<void(RenderDevice*)> drawFunc, RenderDeviceType::Enum rdt, std::string windowName);

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__