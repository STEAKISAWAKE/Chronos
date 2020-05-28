#ifndef __CHRONOS_RENDER_OPENGL_SHADER_H__
#define __CHRONOS_RENDER_OPENGL_SHADER_H__

#include "Shader.h"

class OpenGL_Shader
{

public:
    OpenGL_Shader(std::vector<char> code);
    ~OpenGL_Shader();

public:
    unsigned int programID;

};

#endif // __CHRONOS_RENDER_OPENGL_SHADER_H__