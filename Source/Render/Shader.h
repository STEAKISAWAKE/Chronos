#ifndef __CHRONOS_RENDER_SHADER_H__
#define __CHRONOS_RENDER_SHADER_H__

#include <vector>

class RenderDevice;

class Shader
{

public:
    Shader() {}
    Shader(RenderDevice* renderDevice, std::vector<char> code) {}
    ~Shader() {}

};

#endif // __CHRONOS_RENDER_SHADER_H__