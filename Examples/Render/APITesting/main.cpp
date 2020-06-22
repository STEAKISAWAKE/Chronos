#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include <Render/RenderDevice.h>
#include <Render/Shader.h>
#include <Render/Pipeline.h>
#include <Render/Buffers.h>
#include <Render/Vertex.h>

#include <Utilities/Path.h>

#include <Log.h>

// TODO: remove this include
#include <GLFW/glfw3.h>

RenderDevice* renderDevice;
Shader* vertex;
Shader* fragment;
Pipeline* pipeline;
VertexBuffer* vertexBuffer;
IndexBuffer* indexBuffer;

void Draw(RenderDevice* renDev);

int main()
{
    /* Create a render device with specifics like the Rendering API and the Window name. */
    renderDevice = CreateRenderDevice(Draw, RenderDeviceType::Default, "Chronos Engine - Render API Example");

    /* Tell the render device what the draw function is */
    renderDevice->SetDrawFunction(Draw);

    /* A shader loader to load shader files, it is platform-agnostic. */
    ShaderLoader shaderLoader(renderDevice);

    /* This is how loading a shader is done,  we specifiy the shader file and what the type we want */
    vertex = renderDevice->CreateShader(shaderLoader.LoadShader(getExePath() + "Resources/Shaders/Default/Default.txt", ShaderType::Vertex));
    fragment = renderDevice->CreateShader(shaderLoader.LoadShader(getExePath() + "Resources/Shaders/Default/Default.txt", ShaderType::Fragment));

    /*
        Shaders are combined into a pipelines which give any API just enough information
    */
    pipeline = renderDevice->CreatePipeline(vertex, fragment);

    /* We can now create our vertex/index buffers */

    const std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
    };

    const std::vector<uint32_t> indices = 
    {
        0, 1, 2, 2, 3, 0
    };

    vertexBuffer = renderDevice->CreateVertexBuffer(vertices);
    indexBuffer = renderDevice->CreateIndexBuffer(indices);

    /** Ready to draw allows the render to know that all of the pipelines and shaders have been created. */
    renderDevice->DrawBuffers();

    double previousTime = glfwGetTime();
    int frameCount = 0;

    /* How to specify a game loop */
    while(!renderDevice->ShouldWindowClose())
    {
        /* Calculate FPS */
        double currentTime = glfwGetTime();
        frameCount++;

        if(currentTime - previousTime >= 1.0)
        {
            Log("FPS", std::to_string(frameCount).c_str());

            frameCount = 0;
            previousTime = currentTime;
        }


        /* This will change when there is a proper windowing system */
        glfwPollEvents();

        if(glfwGetKey(renderDevice->window, GLFW_KEY_0) == GLFW_PRESS)
        {
            const std::vector<Vertex> newVertices = {
                {{-0.5f, -1.0f}, {1.0f, 0.0f, 0.0f}},
                {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
                {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
                {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
            };

            vertexBuffer->Set(newVertices);
        }

        /* When we want to draw to the screen we use this */
        renderDevice->DrawFrame();
    }

    renderDevice->DoneRendering();

    /* Anything that you create must be deleted, anything that Chronos creates it deletes. */
    delete indexBuffer;
    delete vertexBuffer;
    
    delete pipeline;

    delete fragment;
    delete vertex;

    delete renderDevice;
}

/*
    In the draw function we are given the render device.
    If another draw command needs to happen this draw function will be recalled.
*/
void Draw(RenderDevice* renDev)
{
    /*
        The draw record can be rerecorded at runtime, it is efficent to rerecord only once when needed (I.e. not every frame).
        In this example we do not need to rerecord the command buffers  
    */
    renDev->BeginRecordDraw();

        /* Binding pipelines is like binding shaders in opengl, you can also edit their variables. */
        pipeline->Bind();

        /* Bind the vertex/index buffer */
        vertexBuffer->Bind();
        indexBuffer->Bind();


    /* Ending a draw recording */
    renDev->EndRecordDraw();
}
