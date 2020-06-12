#ifndef __CHRONOS_RENDER_SHADER_H__
#define __CHRONOS_RENDER_SHADER_H__

#include <vector>
#include <string>

class RenderDevice;

/**
 * Shader type to tell the pipeline.
 */ 
struct ShaderType
{
    enum Enum
    {
        Vertex,
        Fragment
    };
};

/**
 * Create a shader module for a pipeline.
 */
class Shader
{

public:
    /** Default Constructor */
    Shader() {};

    /** Constructor */
    Shader(RenderDevice* renderDevice, std::vector<char> code) {}

    /** Destructor */
    virtual ~Shader() {}

private:
    RenderDevice* renderDevice;

};


/**
 * Loads Shaders from a .shader file.
 */
class ShaderLoader
{

public:
    /** Constructor */
    ShaderLoader(RenderDevice* renderDevice);
    /** Destructor */
    ~ShaderLoader() {}

public:
    /** Load shader from path. */
    std::vector<char> LoadShader(std::string path, ShaderType::Enum shaderType);

private:
    RenderDevice* renderDevice;

};

#endif // __CHRONOS_RENDER_SHADER_H__