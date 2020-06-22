#include "Vulkan_Buffers.h"

#include <string.h>

#include "Vulkan_RenderDevice.h"
#include "Vulkan_Vertex.h"

uint32_t findMemoryType(VkPhysicalDevice physicalDev, uint32_t typeFilter, VkMemoryPropertyFlags properties);
void createBuffer(VkDevice device, VkPhysicalDevice physicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
void copyBuffer(VkDevice device, VkCommandPool commandPool, VkQueue graphicsQueue, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

/*
    Vertex Buffers
*/
Vulkan_VertexBuffer::Vulkan_VertexBuffer(RenderDevice* renderDev, std::vector<Vertex> vertices)
{
    vulkanRenderDevice = static_cast<Vulkan_RenderDevice*>(renderDev);

    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    createBuffer(vulkanRenderDevice->device, vulkanRenderDevice->physicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
    
    void* data;
    vkMapMemory(vulkanRenderDevice->device, stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, vertices.data(), (size_t)bufferSize);
    vkUnmapMemory(vulkanRenderDevice->device, stagingBufferMemory);

    createBuffer(vulkanRenderDevice->device, vulkanRenderDevice->physicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vertexBuffer, vertexBufferMemory);

    copyBuffer(vulkanRenderDevice->device, vulkanRenderDevice->commandPool, vulkanRenderDevice->graphicsQueue, stagingBuffer, vertexBuffer, bufferSize);

    vkDestroyBuffer(vulkanRenderDevice->device, stagingBuffer, nullptr);
    vkFreeMemory(vulkanRenderDevice->device, stagingBufferMemory, nullptr);
}

Vulkan_VertexBuffer::~Vulkan_VertexBuffer()
{
    vkDestroyBuffer(vulkanRenderDevice->device, vertexBuffer, nullptr);
    vkFreeMemory(vulkanRenderDevice->device, vertexBufferMemory, nullptr);
}

void Vulkan_VertexBuffer::Bind()
{
    for(int i = 0; i < vulkanRenderDevice->commandBuffers.size(); i++)
    {
        VkBuffer vertexBuffers[] = {vertexBuffer};
        VkDeviceSize offsets[] = {0};
        vkCmdBindVertexBuffers(vulkanRenderDevice->commandBuffers[i], 0, 1, vertexBuffers, offsets);
    }
}

void Vulkan_VertexBuffer::Set(std::vector<Vertex> vertices)
{
    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    createBuffer(vulkanRenderDevice->device, vulkanRenderDevice->physicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
    
    void* data;
    vkMapMemory(vulkanRenderDevice->device, stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, vertices.data(), (size_t)bufferSize);
    vkUnmapMemory(vulkanRenderDevice->device, stagingBufferMemory);
    
    copyBuffer(vulkanRenderDevice->device, vulkanRenderDevice->commandPool, vulkanRenderDevice->graphicsQueue, stagingBuffer, vertexBuffer, bufferSize);

    vkDestroyBuffer(vulkanRenderDevice->device, stagingBuffer, nullptr);
    vkFreeMemory(vulkanRenderDevice->device, stagingBufferMemory, nullptr);
}

/*
    Index Buffers
*/
Vulkan_IndexBuffer::Vulkan_IndexBuffer(RenderDevice* renderDev, std::vector<uint32_t> indices)
{
    vulkanRenderDevice = static_cast<Vulkan_RenderDevice*>(renderDev);

    VkDeviceSize bufferSize = sizeof(indices[0]) * indices.size();

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    createBuffer(vulkanRenderDevice->device, vulkanRenderDevice->physicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);
    
    void* data;
    vkMapMemory(vulkanRenderDevice->device, stagingBufferMemory, 0, bufferSize, 0, &data);
        memcpy(data, indices.data(), (size_t)bufferSize);
    vkUnmapMemory(vulkanRenderDevice->device, stagingBufferMemory);

    createBuffer(vulkanRenderDevice->device, vulkanRenderDevice->physicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, indexBuffer, indexBufferMemory);

    copyBuffer(vulkanRenderDevice->device, vulkanRenderDevice->commandPool, vulkanRenderDevice->graphicsQueue, stagingBuffer, indexBuffer, bufferSize);

    vkDestroyBuffer(vulkanRenderDevice->device, stagingBuffer, nullptr);
    vkFreeMemory(vulkanRenderDevice->device, stagingBufferMemory, nullptr);
}


Vulkan_IndexBuffer::~Vulkan_IndexBuffer()
{
    vkDestroyBuffer(vulkanRenderDevice->device, indexBuffer, nullptr);
    vkFreeMemory(vulkanRenderDevice->device, indexBufferMemory, nullptr);
}

void Vulkan_IndexBuffer::Bind()
{
    for(int i = 0; i < vulkanRenderDevice->commandBuffers.size(); i++)
    {
        vkCmdBindIndexBuffer(vulkanRenderDevice->commandBuffers[i], indexBuffer, 0, VK_INDEX_TYPE_UINT32);
    }
}

void Vulkan_IndexBuffer::Set(std::vector<uint32_t> indices)
{

}

/* Helpers */
uint32_t findMemoryType(VkPhysicalDevice physicalDev, uint32_t typeFilter, VkMemoryPropertyFlags properties)
{
    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(physicalDev, &memProperties);

    for(uint32_t i = 0; i < memProperties.memoryTypeCount; i++)
    {
        if(typeFilter & (1 << i) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties)
        {
            return i;
        }
    }

    LogError("Vulkan Buffers", "Could not find a suitable memory type!");
    return 0;
}

void createBuffer(VkDevice device, VkPhysicalDevice physicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory)
{
    VkBufferCreateInfo bufferInfo = {};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    VULKAN_CHECK(
        vkCreateBuffer(device, &bufferInfo, nullptr, &buffer),
        "Could not create buffer!"
    )

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(device, buffer, &memRequirements);

    VkMemoryAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = findMemoryType(physicalDevice, memRequirements.memoryTypeBits, properties);

    VULKAN_CHECK(
        vkAllocateMemory(device, &allocInfo, nullptr, &bufferMemory),
        "Could not allocate buffer memory!"
    )

    vkBindBufferMemory(device, buffer, bufferMemory, 0);
}

void copyBuffer(VkDevice device, VkCommandPool commandPool, VkQueue graphicsQueue, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size)
{
    VkCommandBufferAllocateInfo allocInfo = {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = commandPool;
    allocInfo.commandBufferCount = 1;
    
    VkCommandBuffer commandBuffer;
    vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);
    
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    VkBufferCopy copyRegion = {};
    copyRegion.srcOffset = 0;
    copyRegion.dstOffset = 0;
    copyRegion.size = size;

    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);

    vkEndCommandBuffer(commandBuffer);

    VkSubmitInfo submitInfo = {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandBuffer;

    vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(graphicsQueue);

    vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);


}