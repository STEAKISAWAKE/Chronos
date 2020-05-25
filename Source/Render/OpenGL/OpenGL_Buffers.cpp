#include "OpenGL_Buffers.h"

#include <glad/glad.h>

/*
Index Buffer
*/
OpenGL_IndexBuffer::OpenGL_IndexBuffer(const int* data, unsigned int count)
{
    
}

OpenGL_IndexBuffer::~OpenGL_IndexBuffer()
{
    
}

void OpenGL_IndexBuffer::Bind()
{

}

void OpenGL_IndexBuffer::UnBind()
{
    
}

/*
Vertex Buffer
*/
OpenGL_VertexBuffer::OpenGL_VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &VBO_ID);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

OpenGL_VertexBuffer::~OpenGL_VertexBuffer()
{
    glDeleteBuffers(1, &VBO_ID);
}

void OpenGL_VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
}

void OpenGL_VertexBuffer::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}