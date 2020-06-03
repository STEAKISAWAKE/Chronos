#ifndef __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__
#define __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__

#include "RenderDevice.h"

class Vulkan_Shader;
class Vulkan_Pipeline;
class Vulkan_IndexBuffer;
class Vulkan_VertexBuffer;

class Vulkan_RenderDevice
    : public RenderDevice
{

public:
    Vulkan_RenderDevice();
    ~Vulkan_RenderDevice();

public:
    Shader* CreateShader() override;
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;
    IndexBuffer* CreateIndexBuffer() override;
    VertexBuffer* CreateVertexBuffer() override;

};

#endif // __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__