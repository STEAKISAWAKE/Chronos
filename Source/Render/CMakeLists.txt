add_library(ChronosRender STATIC
    RenderDevice.cpp
    Buffers.cpp
    Shader.cpp
    Descriptors.cpp
    Pipeline.cpp
    Material.cpp

    OpenGL/OpenGL_RenderDevice.cpp
    OpenGL/OpenGL_Buffers.cpp
    OpenGL/OpenGL_Shader.cpp
    OpenGL/OpenGL_Descriptors.cpp
    OpenGL/OpenGL_Pipeline.cpp
    OpenGL/OpenGL_Material.cpp
)

target_include_directories(ChronosRender PUBLIC "${CHRONOS_SOURCE}/Render")
target_include_directories(ChronosRender PUBLIC "${CHRONOS_SOURCE}/Utilities")

target_link_libraries(ChronosRender ChronosUtilities)

# 3rd Party
target_link_libraries(ChronosRender glm)
target_link_libraries(ChronosRender glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(ChronosRender OpenGL::GL)

target_link_libraries(ChronosRender glad)
