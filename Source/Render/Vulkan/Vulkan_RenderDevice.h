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

/**
 * Vulkan rendering device
 */
class Vulkan_RenderDevice
    : public RenderDevice
{

public:
    /** Constructor */
    Vulkan_RenderDevice(std::string winName);

    /** Destructor */
    ~Vulkan_RenderDevice();

public:

    /** Create window for Vulkan */
    void CreateWindow(std::string windowName, bool fullscreen) override;

    /** Create shader for Vulkan */
    Shader* CreateShader(std::vector<char> code) override;

    /** Create pipeline for Vulkan */
    Pipeline* CreatePipeline(Shader* vertexShader, Shader* fragmentShader) override;

    /** Create vertex buffer for Vulkan */
    VertexBuffer* CreateVertexBuffer() override;

    /** Create index buffer for Vulkan */
    IndexBuffer* CreateIndexBuffer() override;

    /** Start Draw, if needed the Command Buffer can be dynamically recreated */
    void BeginRecordDraw() override;

    /** End Draw */
    void EndRecordDraw() override;

    /** Draw frame to window */
    void DrawFrame() override;

    void DoneRendering() override;

public:
    /** Vulkan instance handle */
    VkInstance instance;

    /** Debug messenger handle */
    VkDebugUtilsMessengerEXT debugMessenger;

    /** Physical device handle */
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    /** Logical device handle */
    VkDevice device;


    /** Device queues */
    VkQueue graphicsQueue;
    VkQueue presentQueue;


    /** Window surface */
    VkSurfaceKHR surface;

    /** Rendering swapchain */
    VkSwapchainKHR swapChain;

    /** Swapchain images */
    std::vector<VkImage> swapChainImages;

    /** Swapchain image views */
    std::vector<VkImageView> swapChainImageViews;

    /** Swapchain image format */
    VkFormat swapChainImageFormat;

    /** Swapchain extent */
    VkExtent2D swapChainExtent;

    /** Render Pass */
    VkRenderPass renderPass;

    /** Frame Buffers */
    std::vector<VkFramebuffer> swapChainFramebuffers;

    /** Command Pool */
    VkCommandPool commandPool;

    /** Command Buffers */
    std::vector<VkCommandBuffer> commandBuffers;

    /** Used for when binding */
    unsigned int currentCommandBuffer = 0;

    /** GPU-CPU Syncronization*/
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    std::vector<VkFence> imagesInFlight;

    /* Get current frame */
    size_t currentFrame = 0;

public:
    void CreateInstance();
    void SetupDebugMessenger();
    void CreateSurface(std::string winName);
    void PickPhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
    void CreateSwapChainImageViews();
    void CreateRenderPass();
    void CreateFramebuffers();
    void CreateCommandPool();
    void CreateCommandBuffers();
    void CreateSyncObjects();

    void CleanupSwapChain();
    void RecreateSwapChain();

private:
    // A list of pipeline pointers for when we have to recreate the swapchain
    std::vector<Vulkan_Pipeline*> pipelines;

};

#include "Log.h"

/** Check if a Vulkan command was successful */
#define VULKAN_CHECK(vulkanRet, message)    \
    if(vulkanRet != VK_SUCCESS){ LogError("Vulkan Error", message); }

/** Validation layers for debugging */
const std::vector<const char*> validationLayers = 
{
    "VK_LAYER_KHRONOS_validation"
};

/** Extentions for adding to Vulkan */
const std::vector<const char*> deviceExtensions =
{
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

/** Check if debugging */
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

/** Debug callback */
VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData
);

/** Create debug messenger */
VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, 
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
    const VkAllocationCallbacks* pAllocator, 
    VkDebugUtilsMessengerEXT* pDebugMessenger
);

/** Destroy debug messenger */
void DestroyDebugUtilsMessengerEXT(
    VkInstance instance, 
    VkDebugUtilsMessengerEXT debugMessenger, 
    const VkAllocationCallbacks* pAllocator
);

/** A container for the queue families */
struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete();
};

/* Swap chain information */
struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

const int MAX_FRAMES_IN_FLIGHT = 2;

#endif // __CHRONOS_RENDER_VULKAN_RENDERDEVICE_H__