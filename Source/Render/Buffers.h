#ifndef __CHRONOS_RENDER_BUFFERS_H__
#define __CHRONOS_RENDER_BUFFERS_H__

class IndexBuffer
{

public:
    IndexBuffer();
    IndexBuffer(const int* data, unsigned int count);
    ~IndexBuffer();

public:
    void Bind();
    void UnBind();

};

class VertexBuffer
{

public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

public:
    virtual void Bind();
    virtual void UnBind();

};


#endif // __CHRONOS_RENDER_BUFFERS_H__