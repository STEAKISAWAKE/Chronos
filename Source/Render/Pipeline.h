#ifndef __CHRONOS_RENDER_PIPELINE_H__
#define __CHRONOS_RENDER_PIPELINE_H__

#include <string>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

class RenderDevice;
class Shader;

class Pipeline
{

public:
    Pipeline(RenderDevice* renderDevice, Shader* vertexShader, Shader* fragmentShader);
    ~Pipeline();

public:
    virtual void SetIntParameter(const std::string name, const int value) {};
    virtual void SetFloatParameter(const std::string name, const float value) {};
    virtual void SetVector2Parameter(const std::string name, const glm::vec2 value) {};
    virtual void SetVector3Parameter(const std::string name, const glm::vec3 value) {};
    virtual void SetVector4Parameter(const std::string name, const glm::vec4 value) {};
    virtual void SetMatrix2Parameter(const std::string name, const glm::mat2x2 value) {};
    virtual void SetMatrix3Parameter(const std::string name, const glm::mat3x3 value) {};
    virtual void SetMatrix4Parameter(const std::string name, const glm::mat4x4 value) {};

private:
    RenderDevice* renderDevice;

};

#endif // __CHRONOS_RENDER_PIPELINE_H__