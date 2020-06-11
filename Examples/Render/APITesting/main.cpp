#include <Render/RenderDevice.h>
#include <Render/Shader.h>

int main()
{
    RenderDevice* renderDevice = CreateRenderDevice(RenderDeviceType::Default);

    ShaderLoader shaderLoader(renderDevice);

    //renderDevice->CreateShader(shaderLoader.LoadShader());

}






