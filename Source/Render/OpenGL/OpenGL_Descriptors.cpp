#include "OpenGL_Descriptors.h"

#include <glad/glad.h>

OpenGL_Descriptors::OpenGL_Descriptors(std::unordered_map<std::string, Descriptor> descriptorSets)
{
    GLint loc = glGetUniformLocation()
}

OpenGL_Descriptors::~OpenGL_Descriptors()
{
    
}

void OpenGL_Descriptors::Bind()
{

}

void OpenGL_Descriptors::UnBind()
{

}

void OpenGL_Descriptors::UpdateDescriptor(std::string descriptor, void* newData)
{
    descriptors[descriptor].data = newData;
}