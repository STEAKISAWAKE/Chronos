#ifndef __CHRONOS_RENDER_BUFFERS_H__
#define __CHRONOS_RENDER_BUFFERS_H__


/**
 * Vertex buffer to tell the GPU what a models vertices are.
 */
class VertexBuffer
{

public:
    /** Constructor */
    VertexBuffer();

    /** Destructor */
    ~VertexBuffer();

};

/**
 * Index buffer to tell the GPU what vertices to use.
 */
class IndexBuffer
{

public:
    /** Constructor */
    IndexBuffer();

    /** Destrutor */
    ~IndexBuffer();

};

#endif // __CHRONOS_RENDER_BUFFERS_H__