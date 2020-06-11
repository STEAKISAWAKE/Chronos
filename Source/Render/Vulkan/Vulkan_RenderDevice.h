#ifndef __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__
#define __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__

#include "RenderDevice.h"

#include <vulkan/vulkan.h>

#include <vector>
#include <optional>

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
    Shader* CreateShader(std::vector<char> code) override;
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;
    VertexBuffer* CreateVertexBuffer() override;
    IndexBuffer* CreateIndexBuffer() override;

public:
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

};

#include "Log.h"

#define VULKAN_CHECK(vulkanRet, message)    \
    if(vulkanRet != VK_SUCCESS){ LogError("Vulkan Error", message); }

const std::vector<const char*> validationLayers = 
{
    "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions =
{
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData
);

VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, 
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
    const VkAllocationCallbacks* pAllocator, 
    VkDebugUtilsMessengerEXT* pDebugMessenger
);

void DestroyDebugUtilsMessengerEXT(
    VkInstance instance, 
    VkDebugUtilsMessengerEXT debugMessenger, 
    const VkAllocationCallbacks* pAllocator
);

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete();
};

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

#endif // __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__