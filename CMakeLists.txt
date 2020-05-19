cmake_minimum_required(VERSION 3.10)
project(Upsilon CXX)

set(UPSILON_BUILD_GAME ON CACHE BOOL "On to build the game module")
set(UPSILON_BUILD_RENDER ON CACHE BOOL "On to build the render module")

set(UPSILON_RENDER_USE_VULKAN ON CACHE BOOL "On to use vulkan when rendering")

# Build Third Party Libraries
add_subdirectory(ThirdParty)

# Build Upsilon
add_subdirectory(Source)

# Build Examples
add_subdirectory(Examples)