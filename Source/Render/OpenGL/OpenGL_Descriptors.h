#ifndef __CHRONOS_RENDER_OPENGL_DESCRIPTORS_H__
#define __CHRONOS_RENDER_OPENGL_DESCRIPTORS_H__

#include "../Descriptors.h"

#include <unordered_map>

class OpenGL_Shader;

class OpenGL_Descriptors
    : public Descriptors
{

public:
    OpenGL_Descriptors(std::unordered_map<std::string, Descriptor> descriptorSets, OpenGL_Shader* shader);
    ~OpenGL_Descriptors();

public:
    void Bind() override;
    void UnBind() override;
    
    void UpdateDescriptor(std::string descriptor, void* newData);

private:
    /* OpenGL required resource id */
    std::vector<unsigned int> descriptorBinds;

};

#endif // __CHRONOS_RENDER_OPENGL_DESCRIPTORS_H__