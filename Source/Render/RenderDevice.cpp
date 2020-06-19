#include "RenderDevice.h"

#include <GLFW/glfw3.h>

#include "OpenGL/OpenGL_RenderDevice.h"
#include "Vulkan/Vulkan_RenderDevice.h"


/**
 *  Default render device if none is selected.
 */
RenderDeviceType::Enum defaultRenderDeviceType = RenderDeviceType::Vulkan;

RenderDevice::RenderDevice()
{
    
}

RenderDevice::RenderDevice(std::function<void(RenderDevice*)> drawFunc, std::string winName)
{

}

RenderDevice::~RenderDevice()
{
    
}

RenderDevice* CreateRenderDevice(std::function<void(RenderDevice*)> drawFunc, RenderDeviceType::Enum rdt, std::string windowName)
{
    switch(rdt)
    {
        case RenderDeviceType::NoRender:
            return new RenderDevice(drawFunc, windowName);
        break; 

        case RenderDeviceType::Default:
            switch(defaultRenderDeviceType)
            {
                case RenderDeviceType::OpenGL:
                    return new OpenGL_RenderDevice(drawFunc, windowName);
                break;

                case RenderDeviceType::Vulkan:
                    return new Vulkan_RenderDevice(drawFunc, windowName);
                break;
            }
        break;

        case RenderDeviceType::OpenGL:
            return new OpenGL_RenderDevice(drawFunc, windowName);
        break;  

        case RenderDeviceType::Vulkan:
            return new Vulkan_RenderDevice(drawFunc, windowName);
        break;
        
        default:
            switch(defaultRenderDeviceType)
            {
                case RenderDeviceType::OpenGL:
                    return new OpenGL_RenderDevice(drawFunc, windowName);
                break;

                case RenderDeviceType::Vulkan:
                    return new Vulkan_RenderDevice(drawFunc, windowName);
                break;
            }
        break;

    }

    LogError("Render Device", "Could not select a render device!");
    return nullptr;
}

bool RenderDevice::ShouldWindowClose()
{
    return glfwWindowShouldClose(window);
}