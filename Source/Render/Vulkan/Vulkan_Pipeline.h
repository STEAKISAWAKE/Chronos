#ifndef __CHRONOS_RENDER_VULKAN_PIPELINE_H__
#define __CHRONOS_RENDER_VULKAN_PIPELINE_H__

#include "Pipeline.h"

class Vulkan_RenderDevice;
class Vulkan_Shader;

class Vulkan_Pipeline
    : public Pipeline
{

public:
    Vulkan_Pipeline() {}
    Vulkan_Pipeline(RenderDevice* renderDevice, Shader* vertexShader, Shader* fragmentShader);
    ~Vulkan_Pipeline();

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

#endif // __CHRONOS_RENDER_VULKAN_PIPELINE_H__