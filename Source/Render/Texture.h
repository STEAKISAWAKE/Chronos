#ifndef __CHRONOS_RENDER_TEXTURE_H__
#define __CHRONOS_RENDER_TEXTURE_H__

class RenderDevice;

class Texture
{

public:
    Texture(RenderDevice* renderDevice);
    ~Texture();

public:
    void Bind();
    void UnBind();

public:

};

#endif // __CHRONOS_RENDER_TEXTURE_H__