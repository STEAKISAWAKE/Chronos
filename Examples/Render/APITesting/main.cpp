#include <memory>

#include <Render/RenderDevice.h>
#include <Render/Shader.h>
#include <Render/Pipeline.h>

#include <Utilities/Path.h>

// TODO: remove this include
#include <GLFW/glfw3.h>

RenderDevice* renderDevice;
Shader* vertex;
Shader* fragment;
Pipeline* pipeline;

bool Draw(RenderDevice* renDev);

int main()
{
    /* Create a render device with specifics like the Rendering API and the Window name. */
    renderDevice = CreateRenderDevice(RenderDeviceType::Default, "Chronos Engine - Render API Example");

    /* A shader loader to load shader files, it is platform-agnostic. */
    ShaderLoader shaderLoader(renderDevice);

    /* This is how loading a shader is done,  we specifiy the shader file and what the type we want */
    vertex = renderDevice->CreateShader(shaderLoader.LoadShader(getExePath() + "Resources/Shaders/Default/Default.txt", ShaderType::Vertex));
    fragment = renderDevice->CreateShader(shaderLoader.LoadShader(getExePath() + "Resources/Shaders/Default/Default.txt", ShaderType::Fragment));

    /*
        Shaders are combined into a pipelines which give any API just enough information
    */
    pipeline = renderDevice->CreatePipeline(vertex, fragment);

    /* How to specify a game loop */
    while(!renderDevice->ShouldWindowClose())
    {
        /* This will change when there is a proper windowing system */
        glfwPollEvents();

        /* When we want to draw to the screen we use this */
        renderDevice->DrawFrame();
    }

    renderDevice->DoneRendering();

    /* Anything that you create must be deleted, anything that Chronos creates it deletes. */
    delete pipeline;

    delete fragment;
    delete vertex;

    delete renderDevice;
}

/*
    For the draw function we are given the render device,
    the return boolean is if we need to record the draw buffers,
    if we dont want to draw any new meshes or change materials we dont need to return true ever.
    It is efficent to never have to but it will have to happen in most games.

    If you are making a multiplayer game that a mesh dissapears when they die and are respawed at some point,
    just make the mesh invisable and make it reappear sometime else at a different place.
*/

bool Draw(RenderDevice* renDev)
{
    /*
        The draw record can be rerecorded at runtime, it is efficent to rerecord only once when needed (I.e. not every frame).
        In this example we do not need to rerecord the command buffers  
    */
    renderDevice->BeginRecordDraw();

        /* Binding pipelines is like binding shaders in opengl, you can also edit their variables. */
        pipeline->Bind();

    /* Ending a draw recording */
    renderDevice->EndRecordDraw();
}
