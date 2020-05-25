cmake_minimum_required(VERSION 3.10)
project(Chronos CXX)

set(CHRONOS_BUILD_GAME ON CACHE BOOL "On to build the game module")
set(CHRONOS_BUILD_RENDER ON CACHE BOOL "On to build the render module")

set(CHRONOS_RENDER_USE_VULKAN ON CACHE BOOL "On to use vulkan when rendering")

# Build Third Party Libraries
add_subdirectory(ThirdParty)

set(CHRONOS_SOURCE "${PROJECT_SOURCE_DIR}/Source")

# Build Chronos
add_subdirectory(Source)

# Build Examples
add_subdirectory(Examples)