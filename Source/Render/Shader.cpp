#include "Shader.h"

#include <fstream>

#include "RenderDevice.h"
#include "File.h"
#include "Log.h"

#include "json.hpp"

ShaderLoader::ShaderLoader(RenderDevice* renderDev)
{
    renderDevice = renderDev;
}

nlohmann::json LoadShaderOfType(nlohmann::json shaders, ShaderType::Enum typeToLoad)
{
    switch (typeToLoad)
    {

        case ShaderType::Vertex:
            return shaders["Vertex"];
        break;

        case ShaderType::Fragment:
            return shaders["Fragment"];
        break;

        default:
            LogError("Load Shader", "Invalid shader type!");
        break;
    };

    return nlohmann::json();
}

std::vector<char> 
ShaderLoader::LoadShader(std::string path, ShaderType::Enum shaderType)
{
    if(!DoesFileExist(path))
    {
        LogError("Shader Loader", "File does not exist!");
        return std::vector<char>();
    }

    // Load .shader code from file
    std::ifstream jsonFile(path.c_str());
    nlohmann::json shaderJson;
    jsonFile >> shaderJson;

    // Determine which code to use from JSON
    switch(renderDevice->renderType)
    {

        // In the case of a NoRender lets do nothing
        case RenderDeviceType::NoRender:
            Log("Shader Loader", "No render type.");
        break;

        // Load OpenGL code
        case RenderDeviceType::OpenGL:
            return LoadShaderOfType(shaderJson["OpenGL"], shaderType);
        break;

        // Load Vulkan code
        case RenderDeviceType::Vulkan:
            return LoadShaderOfType(shaderJson["Vulkan"], shaderType);
        break;

    };

    return std::vector<char>();
}