#ifndef __CHRONOS_RENDER_RENDERDEVICE_H__
#define __CHRONOS_RENDER_RENDERDEVICE_H__

struct GLFWwindow;

class VertexBuffer;
class IndexBuffer;

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

    virtual VertexBuffer* CreateVertexBuffer() {}
    virtual IndexBuffer* CreateIndexBuffer() {}

    virtual void BeginDraw() {}
    virtual void DrawMesh() {}
    virtual void EndDraw() {}

};

#endif // __CHRONOS_RENDER_RENDERDEVICE_H__