#ifndef __CHRONOS_RENDER_VULKAN_SHADER_H__
#define __CHRONOS_RENDER_VULKAN_SHADER_H__

#include "Shader.h"

class Vulkan_RenderDevice;

class Vulkan_Shader
    : public Shader
{

public:
    Vulkan_Shader(Vulkan_RenderDevice* renderDevice, std::vector<char> code);
    ~Vulkan_Shader();

};

#endif // __CHRONOS_RENDER_VULKAN_SHADER_H__