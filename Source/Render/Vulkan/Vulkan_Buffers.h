#ifndef __CHRONOS_RENDER_VULKAN_BUFFERS_H__
#define __CHRONOS_RENDER_VULKAN_BUFFERS_H__

#include "Buffers.h"

#include <vulkan/vulkan.h>

class Vulkan_RenderDevice;

/**
 * Vertex buffer to tell the GPU what a models vertices are.
 */
class Vulkan_VertexBuffer
    : public VertexBuffer
{

public:
    /** Constructor */
    Vulkan_VertexBuffer(RenderDevice* renderDev, std::vector<Vertex> vertices);

    /** Destructor */
    ~Vulkan_VertexBuffer();

public:
    /* Connect the vertex buffer when rendering. */
    void Bind();

    /* Change the data in the buffer */
    void Set(std::vector<Vertex> vertices);

private:
    Vulkan_RenderDevice* vulkanRenderDevice;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
};



/**
 * Index buffer to tell the GPU what vertices to use.
 */
class Vulkan_IndexBuffer
    : public IndexBuffer
{

public:
    /** Constructor */
    Vulkan_IndexBuffer(RenderDevice* renderDev, std::vector<uint32_t> indices);

    /** Destrutor */
    ~Vulkan_IndexBuffer();

public:
    void Bind();
    void Set(std::vector<uint32_t> indices);

private:
    Vulkan_RenderDevice* vulkanRenderDevice;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
};

uint32_t findMemoryType(VkPhysicalDevice physicalDev, uint32_t typeFilter, VkMemoryPropertyFlags properties);
void createBuffer(VkDevice device, VkPhysicalDevice physicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
void copyBuffer(VkDevice device, VkCommandPool commandPool, VkQueue graphicsQueue, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

#endif // __CHRONOS_RENDER_VULKAN_BUFFERS_H__