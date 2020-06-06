#ifndef __CHRONOS_RENDER_VULKAN_BUFFERS_H__
#define __CHRONOS_RENDER_VULKAN_BUFFERS_H__


#include <stdint.h>

#include <glm/vec3.hpp>

/**
 * Vertex buffer to tell the GPU what a models vertices are.
 */
class Vulkan_VertexBuffer
{

public:
    /** Constructor */
    Vulkan_VertexBuffer(std::vector<glm::vec3> vertices);

    /** Destructor */
    ~Vulkan_VertexBuffer();

};

/**
 * Index buffer to tell the GPU what vertices to use.
 */
class Vulkan_IndexBuffer
{

public:
    /** Constructor */
    Vulkan_IndexBuffer(std::vector<uint32_t> indices);

    /** Destrutor */
    ~Vulkan_IndexBuffer();

};

#endif // __CHRONOS_RENDER_VULKAN_BUFFERS_H__