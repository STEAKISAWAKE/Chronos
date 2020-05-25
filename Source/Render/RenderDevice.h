#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

struct GLFWwindow;

class VertexBuffer;
class IndexBuffer;
class Descriptors;

class RenderDevice
{

public:
    RenderDevice();
    ~RenderDevice();

public:
    GLFWwindow* window;

public:
    virtual void Initalize() {}
    virtual void Terminate() {}

    virtual void CreateWindow() {}
    virtual void CloseWindow() {}

    virtual VertexBuffer*   CreateVertexBuffer() { return nullptr; }
    virtual IndexBuffer*    CreateIndexBuffer() { return nullptr; }
    virtual Descriptors*    CreateDescriptors() { return nullptr; }

    virtual void BeginDraw() {}
    virtual void EndDraw() {}

    virtual void Present() {}

    virtual void Clear() {} 

};

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__