#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

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

   //std::cout << jsonFile.rdbuf() << std::endl;

    if(!jsonFile.is_open())
        LogError("Shader Loader", "Error opening file.");
    
    nlohmann::json shaderJson;

    try
    {
        jsonFile >> shaderJson;
    }
    catch(const std::exception& e)
    {
        std::cout << jsonFile.rdbuf() << std::endl;
        std::cerr << e.what() << '\n';
    }

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
            size_t found = path.find_last_of("/\\");
            std::string pathWithoutFile = std::string(path).substr(0, found);

            std::string shaderPath(pathWithoutFile + "/" + std::string(LoadShaderOfType(shaderJson["Vulkan"], shaderType)));

            Log("Shader Testing", shaderPath.c_str());

            std::ifstream shaderFile(shaderPath.c_str(), std::ios::ate | std::ios::binary);
            
            size_t fileSize = (size_t) shaderFile.tellg();
            std::vector<char> buffer(fileSize);

            shaderFile.seekg(0);
            shaderFile.read(buffer.data(), fileSize);

            shaderFile.close();

            return buffer;
        break;

    };

    return std::vector<char>();
}