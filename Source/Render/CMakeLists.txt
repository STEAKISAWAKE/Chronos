add_library(ChronosRender STATIC
    RenderDevice.cpp
    Buffers.cpp
    Descriptors.cpp

    OpenGL/OpenGL_RenderDevice.cpp
    OpenGL/OpenGL_Buffers.cpp
    OpenGL/OpenGL_Descriptors.cpp
)

target_include_directories(ChronosRender PUBLIC "${CHRONOS_SOURCE}/Utilities")

target_link_libraries(ChronosRender ChronosUtilities)

# 3rd Party
target_link_libraries(ChronosRender glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(ChronosRender OpenGL::GL)

target_link_libraries(ChronosRender glad)
