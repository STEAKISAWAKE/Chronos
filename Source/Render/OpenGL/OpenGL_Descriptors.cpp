#include "OpenGL_Descriptors.h"

#include <glad/glad.h>

#include "OpenGL_Shader.h"

OpenGL_Descriptors::OpenGL_Descriptors(std::unordered_map<std::string, Descriptor> descriptorSets, OpenGL_Pipeline* pipeline)
{

    for(auto descriptor : descriptorSets)
    {
        //GLint loc = glGetUniformLocation(shader->programID, descriptor.first.c_str());
    }


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