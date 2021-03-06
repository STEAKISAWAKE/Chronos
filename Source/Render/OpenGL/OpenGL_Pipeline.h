#ifndef __CHRONOS_RENDER_OPENGL_PIPELINE_H__
#define __CHRONOS_RENDER_OPENGL_PIPELINE_H__

#include "Pipeline.h"

class OpenGL_RenderDevice;
class OpenGL_Shader;

class OpenGL_Pipeline
    : public Pipeline
{

public:
    OpenGL_Pipeline(OpenGL_RenderDevice* renderDevice, OpenGL_Shader* vertexShader, OpenGL_Shader* fragmentShader);
    ~OpenGL_Pipeline();

public:
    void SetIntParameter(const std::string name, const int value) override;
    void SetFloatParameter(const std::string name, const float value) override;
    void SetVector2Parameter(const std::string name, const glm::vec2 value) override;
    void SetVector3Parameter(const std::string name, const glm::vec3 value) override;
    void SetVector4Parameter(const std::string name, const glm::vec4 value) override;
    void SetMatrix2Parameter(const std::string name, const glm::mat2x2 value) override;
    void SetMatrix3Parameter(const std::string name, const glm::mat3x3 value) override;
    void SetMatrix4Parameter(const std::string name, const glm::mat4x4 value) override;

};

#endif // __CHRONOS_RENDER_OPENGL_PIPELINE_H__