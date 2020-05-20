#ifndef __UPSILON_RENDER_VERTEXBUFFER_H__
#define __UPSILON_RENDER_VERTEXBUFFER_H__

class IndexBuffer
{

public:
    IndexBuffer(const int* data, unsigned int count);
    ~IndexBuffer();

    void Bind();
    void UnBind();

};

#endif // __UPSILON_RENDER_VERTEXBUFFER_H__