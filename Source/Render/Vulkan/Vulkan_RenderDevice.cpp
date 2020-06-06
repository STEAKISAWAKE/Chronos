#include "Vulkan_RenderDevice.h"

#include "GLFW/glfw3.h"

#include <assert.h>

bool checkValidationLayerSupport();

Vulkan_RenderDevice::Vulkan_RenderDevice()
{
    assert(glfwVulkanSupported() == GLFW_TRUE && "Vulkan Render Device: Could not load Vulkan as it is not supported!");

    if(enableValidationLayers && !checkValidationLayerSupport())
    {
        LogError("Vulkan Validation Layers", "Could not use validation layers, but requested!");
    }

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
    
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    instanceCreateInfo.enabledExtensionCount = glfwExtensionCount;
    
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
    instanceCreateInfo.ppEnabledExtensionNames = glfwExtensions;


    VULKAN_CHECK(
        vkCreateInstance(&instanceCreateInfo, nullptr, &instance), 
        "Could not create instance!"
    );

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
