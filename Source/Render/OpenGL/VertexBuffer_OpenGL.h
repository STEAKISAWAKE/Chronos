#ifndef __CHRONOS_RENDER_VERTEXBUFFER_OPENGL_H__
#define __CHRONOS_RENDER_VERTEXBUFFER_OPENGL_H__

#include "../VertexBuffer.h"

class VertexBuffer_OpenGL
    : public VertexBuffer
{

public:
    VertexBuffer_OpenGL(const void* data, unsigned int size);
    ~VertexBuffer_OpenGL();

    void Bind() override;
    void UnBind() override;

};

#endif // __CHRONOS_RENDER_VERTEXBUFFER_OPENGL_H__