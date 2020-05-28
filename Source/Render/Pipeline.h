#ifndef __CHRONOS_RENDER_SHADER_H__
#define __CHRONOS_RENDER_SHADER_H__

#include <vector>

class Shader;

class Pipeline
{

public:
    Pipeline();
    Pipeline(Shader* vertexShader, Shader* fragmentShader);
    ~Pipeline();

public:
    

};

#endif // __CHRONOS_RENDER_SHADER_H__
