#ifndef __UPSILON_RENDER_RENDERDEVICE_H__
#define __UPSILON_RENDER_RENDERDEVICE_H__

#include "RenderDevice.h"

class RenderDevice
{

public:
    virtual void Initalize() {}

    virtual void CreateWindow() {}

};

#endif // __UPSILON_RENDER_RENDERDEVICE_H__