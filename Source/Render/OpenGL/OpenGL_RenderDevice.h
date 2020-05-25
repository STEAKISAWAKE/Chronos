#ifndef __CHRONOS_RENDER_RENDERDEVICE_OPENGL_H__
#define __CHRONOS_RENDER_RENDERDEVICE_OPENGL_H__

#include "../RenderDevice.h"

class RenderDevice_OpenGL
    : public RenderDevice
{

public:
    RenderDevice_OpenGL();
    ~RenderDevice_OpenGL();

public:
    void Initalize() override;
    void Terminate() override;

    void CreateWindow() override;

    void BeginDraw() override;
    void EndDraw() override;

};

#endif // __CHRONOS_RENDER_RENDERDEVICE_OPENGL_H__