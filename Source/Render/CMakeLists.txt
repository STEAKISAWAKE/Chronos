add_library(ChronosRender STATIC
    RenderDevice.cpp
    VertexBuffer.cpp

    OpenGL/RenderDevice_OpenGL.cpp
    OpenGL/VertexBuffer_OpenGL.cpp
)

target_include_directories(ChronosRender "${CHRONOS_SOURCE}/Utilities")

target_link_libraries(ChronosRender ChronosUtilities)

# 3rd Party
target_link_libraries(ChronosRender glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(ChronosRender OpenGL::GL)

target_link_libraries(ChronosRender glad)
