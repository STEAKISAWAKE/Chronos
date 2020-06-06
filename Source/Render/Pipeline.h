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


/**
 * Pipeline to connect shaders and set their parameters
 * 
 * When a material is used it will have a pipeline.
 * A material instance will have a pointer to the original material and can set the pipelines parameters.
 */
class Pipeline
{

public:
    /** Constructor (INTERNAL USE ONLY) */
    Pipeline(RenderDevice* renderDevice, Shader* vertexShader, Shader* fragmentShader);

    /** Desctructor */
    ~Pipeline();

public:
    /** Set pipeline int parameter. */
    virtual void SetIntParameter(const std::string name, const int value) {};

    /** Set pipeline float parameter. */
    virtual void SetFloatParameter(const std::string name, const float value) {};

    /** Set pipeline Vector 2 parameter. */
    virtual void SetVector2Parameter(const std::string name, const glm::vec2 value) {};

    /** Set pipeline Vector 3 parameter. */
    virtual void SetVector3Parameter(const std::string name, const glm::vec3 value) {};

    /** Set pipeline Vector 4 parameter */
    virtual void SetVector4Parameter(const std::string name, const glm::vec4 value) {};

    /** Set pipeline Matrix 2 parameter. */
    virtual void SetMatrix2Parameter(const std::string name, const glm::mat2x2 value) {};

    /** Set pipeline Matrix 3 parameter. */
    virtual void SetMatrix3Parameter(const std::string name, const glm::mat3x3 value) {};

    /** Set pipeline Matrix 4 parameter. */
    virtual void SetMatrix4Parameter(const std::string name, const glm::mat4x4 value) {};

private: 
    RenderDevice* renderDevice;

};

#endif // __CHRONOS_RENDER_PIPELINE_H__