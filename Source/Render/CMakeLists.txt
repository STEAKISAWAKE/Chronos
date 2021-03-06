add_library(ChronosRender STATIC
    RenderDevice.cpp
    Shader.cpp
    Pipeline.cpp
    Vertex.cpp
    Buffers.cpp

    OpenGL/OpenGL_Shader.cpp
    OpenGL/OpenGL_Pipeline.cpp
    OpenGL/OpenGL_RenderDevice.cpp

    Vulkan/Vulkan_RenderDevice.cpp
    Vulkan/Vulkan_Shader.cpp
    Vulkan/Vulkan_Pipeline.cpp
    Vulkan/Vulkan_Vertex.cpp
    Vulkan/Vulkan_Buffers.cpp

)

target_include_directories(ChronosRender PUBLIC "${CHRONOS_SOURCE}/Render")
target_include_directories(ChronosRender PUBLIC "${CHRONOS_SOURCE}/Utilities")

target_link_libraries(ChronosRender ChronosUtilities)

# 3rd Party
target_link_libraries(ChronosRender glm)
target_link_libraries(ChronosRender glfw)
target_link_libraries(ChronosRender glad)


find_package(OpenGL REQUIRED)
target_include_directories(ChronosRender PUBLIC OPENGL_INCLUDE_DIR)
target_link_libraries(ChronosRender OpenGL::GL)

find_package(Vulkan REQUIRED)
target_include_directories(ChronosRender PUBLIC "${Vulkan_INCLUDE_DIRS}")
target_link_libraries(ChronosRender "${Vulkan_LIBRARY}")
