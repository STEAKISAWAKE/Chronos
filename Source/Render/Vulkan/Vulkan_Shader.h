#ifndef __CHRONOS_RENDER_VULKAN_SHADER_H__
#define __CHRONOS_RENDER_VULKAN_SHADER_H__

#include "Shader.h"

#include <vulkan/vulkan.h>

class Vulkan_RenderDevice;

class Vulkan_Shader
    : public Shader
{

public:
    Vulkan_Shader(RenderDevice* renderDevice, std::vector<char> code);
    ~Vulkan_Shader();

private:
    Vulkan_RenderDevice* vulkanRenderDevice;

    VkShaderModule shaderModule;

};

#endif // __CHRONOS_RENDER_VULKAN_SHADER_H__