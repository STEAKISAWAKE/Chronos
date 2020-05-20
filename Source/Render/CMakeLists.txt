add_library(UpsilonRender STATIC
    RenderDevice.cpp
    VertexBuffer.cpp

    OpenGL/RenderDevice_OpenGL.cpp
    OpenGL/VertexBuffer_OpenGL.cpp
    OpenGL/IndexBuffer_OpenGL.cpp
)