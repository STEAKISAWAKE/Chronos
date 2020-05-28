#ifndef __CHRONOS_RENDER_BUFFERS_OPENGL_H__
#define __CHRONOS_RENDER_BUFFERS_OPENGL_H__

#include "Buffers.h"

class OpenGL_IndexBuffer
    : public IndexBuffer
{

public:
    OpenGL_IndexBuffer(const int* data, unsigned int count);
    ~OpenGL_IndexBuffer();

public:
    void Bind();
    void UnBind();


};

class OpenGL_VertexBuffer
    : public VertexBuffer
{

public:
    OpenGL_VertexBuffer(const void* data, unsigned int size);
    ~OpenGL_VertexBuffer();

public:
    void Bind() override;
    void UnBind() override;

private:
    unsigned int VBO_ID;

};

#endif // __CHRONOS_RENDER_BUFFERS_OPENGL_H__