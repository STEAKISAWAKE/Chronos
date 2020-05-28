#ifndef __CHRONOS_RENDER_OPENGL_SHADER_H__
#define __CHRONOS_RENDER_OPENGL_SHADER_H__

#include "Pipeline.h"

class OpenGL_Shader;

class OpenGL_Pipeline
    : public Pipeline
{

public:
    OpenGL_Pipeline(OpenGL_Shader* vertexShader, OpenGL_Shader* fragmentShader);
    ~OpenGL_Pipeline();

};

#endif // __CHRONOS_RENDER_OPENGL_SHADER_H__