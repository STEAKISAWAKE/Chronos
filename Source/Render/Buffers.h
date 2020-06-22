#ifndef __CHRONOS_RENDER_BUFFERS_H__
#define __CHRONOS_RENDER_BUFFERS_H__

#include <stdint.h>
#include <vector>

#include <glm/vec3.hpp>

class RenderDevice;
class Vertex;

/**
 * Vertex buffer to tell the GPU what a models vertices are.
 */
class VertexBuffer
{

public:
    /** Default Constructor */
    VertexBuffer() {}

    /** Constructor */
    VertexBuffer(RenderDevice* renderDev, std::vector<Vertex> vertices) {};

    /** Destructor */
    virtual ~VertexBuffer() {};

public:
    virtual void Bind() {}
    virtual void Set(std::vector<Vertex> vertices) {}

public:
    RenderDevice* renderDevice;

};

/**
 * Index buffer to tell the GPU what vertices to use.
 */
class IndexBuffer
{

public:
    /** Default Constructor*/
    IndexBuffer() {}

    /** Constructor */
    IndexBuffer(RenderDevice* renderDev, std::vector<uint32_t> indices) {};

    /** Destrutor */
    virtual ~IndexBuffer() {};

public:
    virtual void Bind() {}
    virtual void Set(std::vector<uint32_t> indices) {}

public:
    RenderDevice* renderDevice;

};

#endif // __CHRONOS_RENDER_BUFFERS_H__