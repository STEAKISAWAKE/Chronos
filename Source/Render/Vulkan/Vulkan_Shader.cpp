#include "Vulkan_Shader.h"

#include "Vulkan_RenderDevice.h"

Vulkan_Shader::Vulkan_Shader(RenderDevice* renderDev, std::vector<char> code)
{
    vulkanRenderDevice = static_cast<Vulkan_RenderDevice*>(renderDev);

    VkShaderModuleCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.flags = 0;
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

    //VULKAN_CHECK(
    //    vkCreateShaderModule(),
    //    "Could not create shader module!"
    //);
}

Vulkan_Shader::~Vulkan_Shader()
{

}