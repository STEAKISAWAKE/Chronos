#ifndef __CHRONOS_RENDER_MATERIAL_H__
#define __CHRONOS_RENDER_MATERIAL_H__

#include <string>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

class Descriptor;
class Texture;

class Material
{

public:
    Material();
    ~Material();

public:
    virtual void SetIntParameter(std::string name, int value) {}
    virtual void SetFloatParameter(std::string name, float value) {}
    virtual void SetVector2Parameter(std::string name, glm::vec2 value) {}
    virtual void SetVector3Parameter(std::string name, glm::vec3 value) {}
    virtual void SetVector4Parameter(std::string name, glm::vec4 value) {}
    virtual void SetMatrixParameter(std::string name, glm::mat4 value) {}
    virtual void SetSamplerParameter(std::string name, Texture* value) {}

protected:



};

#endif // __CHRONOS_RENDER_MATERIAL_H__