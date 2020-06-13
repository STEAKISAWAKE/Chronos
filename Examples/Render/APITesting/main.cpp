#include <memory>

#include <Render/RenderDevice.h>
#include <Render/Shader.h>
#include <Render/Pipeline.h>

#include <GLFW/glfw3.h>

int main()
{
    RenderDevice* renderDevice = CreateRenderDevice(RenderDeviceType::Default);

    ShaderLoader shaderLoader(renderDevice);

    Shader* vertex = renderDevice->CreateShader(shaderLoader.LoadShader("C:\\Users\\Steak\\Documents\\Chronos\\Resources\\Shaders\\Default\\Default.txt", ShaderType::Vertex));
    Shader* fragment = renderDevice->CreateShader(shaderLoader.LoadShader("C:\\Users\\Steak\\Documents\\Chronos\\Resources\\Shaders\\Default\\Default.txt", ShaderType::Fragment));

    Pipeline* pipeline = renderDevice->CreatePipeline(vertex, fragment);

    renderDevice->BeginRecordDraw();

    pipeline->Bind();

    renderDevice->EndRecordDraw();
        

    while(!renderDevice->ShouldWindowClose())
    {
        glfwPollEvents();
        renderDevice->DrawFrame();
    }

    delete pipeline;

    delete fragment;
    delete vertex;

    delete renderDevice;
}
