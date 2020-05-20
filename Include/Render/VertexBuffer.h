#ifndef __UPSILON_RENDER_VERTEXBUFFER_H__
#define __UPSILON_RENDER_VERTEXBUFFER_H__

class VertexBuffer
{

public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    virtual void Bind();
    virtual void UnBind();

};

#endif // __UPSILON_RENDER_VERTEXBUFFER_H__