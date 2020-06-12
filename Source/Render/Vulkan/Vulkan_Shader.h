#ifndef __CHRONOS_RENDER_VULKAN_SHADER_H__
#define __CHRONOS_RENDER_VULKAN_SHADER_H__

#include "Shader.h"

#include <vulkan/vulkan.h>

class Vulkan_RenderDevice;

/**
 *  Vulkan shaders
 */
class Vulkan_Shader
    : public Shader
{

public:
    /** Constructor */
    Vulkan_Shader(RenderDevice* renderDevice, std::vector<char> code);
    
    /** Destructor */
    ~Vulkan_Shader();

public:
    /** Shader module handle */
    VkShaderModule shaderModule;

private:
    /** Vulkan Render Device */
    Vulkan_RenderDevice* vulkanRenderDevice;

};

#endif // __CHRONOS_RENDER_VULKAN_SHADER_H__