#ifndef __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__
#define __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__

#include "RenderDevice.h"

#include <Vulkan/vulkan.h>

#include <vector>

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
    void CreateWindow(std::string windowName, bool fullscreen) override;
    Shader* CreateShader() override;
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;
    VertexBuffer* CreateVertexBuffer() override;
    IndexBuffer* CreateIndexBuffer() override;

public:
    VkInstance instance;

};

#include "Log.h"

#define VULKAN_CHECK(vulkanRet, message)    \
    if(vulkanRet != VK_SUCCESS)             \
        LogError("Vulkan Error", message);

const std::vector<const char*> validationLayers = 
{
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

#endif // __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__