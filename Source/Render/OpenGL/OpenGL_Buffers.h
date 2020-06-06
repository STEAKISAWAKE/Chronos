#ifndef __CHRONOS_RENDER_OPENGL_BUFFERS_H__
#define __CHRONOS_RENDER_OPENGL_BUFFERS_H__


/**
 * Vertex buffer to tell the GPU what a models vertices are.
 */
class OpenGL_VertexBuffer
{

public:
    /** Constructor */
    OpenGL_VertexBuffer();

    /** Destructor */
    ~OpenGL_VertexBuffer();

};

/**
 * Index buffer to tell the GPU what vertices to use.
 */
class OpenGL_IndexBuffer
{

public:
    /** Constructor */
    OpenGL_IndexBuffer();

    /** Destrutor */
    ~OpenGL_IndexBuffer();

};

#endif // __CHRONOS_RENDER_OPENGL_BUFFERS_H__