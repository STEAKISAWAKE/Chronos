#ifndef __CHRONOS_RENDER_VERTEXBUFFER_H__
#define __CHRONOS_RENDER_VERTEXBUFFER_H__

class VertexBuffer
{

public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    virtual void Bind();
    virtual void UnBind();

};

#endif // __CHRONOS_RENDER_VERTEXBUFFER_H__