#include "Vulkan_RenderDevice.h"

#include <cstring>
#include <assert.h>

#include "GLFW/glfw3.h"

#include "Vulkan_Shader.h"
#include "Vulkan_Pipeline.h"

bool checkValidationLayerSupport();
std::vector<const char*> getRequiredExtensions();
VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

Vulkan_RenderDevice::Vulkan_RenderDevice()
{
    assert(glfwVulkanSupported() == GLFW_TRUE && "Vulkan Render Device: Could not load Vulkan as it is not supported!");

    if(enableValidationLayers && !checkValidationLayerSupport())
    {
        LogError("Vulkan Validation Layers", "Could not use validation layers, but requested!");
    }

    /** CREATE INSTANCE **/
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.apiVersion = VK_VERSION_1_2;
    appInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
    appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
    appInfo.pApplicationName = "Chronos Game";
    appInfo.pEngineName = "Chronos";
    appInfo.pNext = nullptr;

    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    
    auto extensions = getRequiredExtensions();
    instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    instanceCreateInfo.ppEnabledExtensionNames = extensions.data();

    if(enableValidationLayers)
    {
        instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        instanceCreateInfo.ppEnabledLayerNames = validationLayers.data();
    }
    else
    {
        instanceCreateInfo.enabledExtensionCount = 0;
    }

    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pApplicationInfo = &appInfo;
    instanceCreateInfo.pNext = nullptr;


    VULKAN_CHECK(
        vkCreateInstance(&instanceCreateInfo, nullptr, &instance), 
        "Could not create instance!"
    );

    /** SETUP DEBUG MESSENGER **/
    if(enableValidationLayers)
    {
        VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo;
        debugMessengerCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        debugMessengerCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        debugMessengerCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        debugMessengerCreateInfo.pfnUserCallback = debugCallback;
        debugMessengerCreateInfo.pUserData = nullptr;

        VULKAN_CHECK(
            CreateDebugUtilsMessengerEXT(instance, &debugMessengerCreateInfo, nullptr, &debugMessenger),
            "Could not setup debug manager"
        )
    }

}

Vulkan_RenderDevice::~Vulkan_RenderDevice()
{

    vkDestroyInstance(instance, nullptr);

}

void Vulkan_RenderDevice::CreateWindow(std::string windowName, bool fullscreen)
{

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);

    int monitorWidth = vidmode->width, monitorHeight = vidmode->height;

    if(fullscreen)
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwCreateWindow(monitorWidth, monitorHeight, windowName.c_str(), monitor, nullptr);
    }
    else
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwCreateWindow(monitorWidth, monitorHeight, windowName.c_str(), nullptr, nullptr);
    }
}

Shader* Vulkan_RenderDevice::CreateShader(std::vector<char> code)
{
    return new Vulkan_Shader(this, code);
}

Pipeline* Vulkan_RenderDevice::CreatePipeline(Shader* vertexShader, Shader* fragmentShader)
{
    return new Vulkan_Pipeline(this, static_cast<Vulkan_Shader*>(vertexShader), static_cast<Vulkan_Shader*>(fragmentShader));
}

//VertexBuffer* Vulkan_RenderDevice::CreateVertexBuffer(std::vector<Vertex>)
//{

//}

// HELPERS //
bool checkValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for(const char* layerName : validationLayers)
    {
        bool layerFound = false;

        for(const auto& layerProperties : availableLayers)
        {
            if(strcmp(layerName, layerProperties.layerName) == 0)
            {
                layerFound = true;
                break;
            }
        }

        if(!layerFound)
        {
            return false;
        }
    }

    return true;
}

std::vector<const char*> getRequiredExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if(enableValidationLayers)
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

    return extensions;
}

VkBool32 debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData)
{
    LogError("Vulkan Validation Layer", pCallbackData->pMessage);

    return VK_FALSE;
}

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger)
{
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if(func != nullptr)
    {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    }
    else
    {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
