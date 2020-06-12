#ifndef __CHRONOS_RENDER_VULKAN_PIPELINE_H__
#define __CHRONOS_RENDER_VULKAN_PIPELINE_H__

#include "Pipeline.h"

#include <vulkan/vulkan.h>

class Vulkan_RenderDevice;
class Vulkan_Shader;

/**
 * Vulkan pipeline
 */
class Vulkan_Pipeline
    : public Pipeline
{

public:
    /** Default Constructor (NOT USED) */
    Vulkan_Pipeline() {}

    /** Constructor (INTERNAL USE) */
    Vulkan_Pipeline(RenderDevice* renderDevice, Shader* vertexShader, Shader* fragmentShader);

    /** Destructor */
    ~Vulkan_Pipeline();

public:
    /** Set int parameter on pipeline */
    void SetIntParameter(const std::string name, const int value) override;

    /** Set float parameter on pipeline */
    void SetFloatParameter(const std::string name, const float value) override;

    /** Set Vector 2 parameter on pipeline */
    void SetVector2Parameter(const std::string name, const glm::vec2 value) override;

    /** Set Vector 3 parameter on pipeline */
    void SetVector3Parameter(const std::string name, const glm::vec3 value) override;

    /** Set Vector 4 parameter on pipeline */
    void SetVector4Parameter(const std::string name, const glm::vec4 value) override;

    /** Set Matrix 2 parameter on pipeline */
    void SetMatrix2Parameter(const std::string name, const glm::mat2x2 value) override;

    /** Set Matrix 3 parameter on pipeline */
    void SetMatrix3Parameter(const std::string name, const glm::mat3x3 value) override;

    /** Set Matrix 4 parameter on pipeline */
    void SetMatrix4Parameter(const std::string name, const glm::mat4x4 value) override;

private:
    Vulkan_RenderDevice* vulkanRenderDevice;
    Vulkan_Shader* vertexShader;
    Vulkan_Shader* fragmentShader;

    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

};

#endif // __CHRONOS_RENDER_VULKAN_PIPELINE_H__