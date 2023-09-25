#pragma once
#include <GL/glew.h>
#include <iostream>
void GLClearError();
GLenum GLGetError();
void GLPrintError(GLenum err, const char* func, const char* file, int line);
#define GLCall(x) GLClearError();\
    x;\
    GLPrintError(GLGetError(),#x,__FILE__,__LINE__)


class VertexArray;
class IndexBuffer;

struct Texture2DConfig
{
    Texture2DConfig(uint32_t wrap_s, uint32_t wrap_t)
        :WRAP_S(wrap_s), WRAP_T(wrap_t), BORDER_COLOR{ 0,0,0,0 },
        MIN_FILTER(GL_NEAREST), MAG_FILTER(GL_LINEAR)
    {}
    Texture2DConfig()
        :WRAP_S(GL_MIRRORED_REPEAT), WRAP_T(GL_MIRRORED_REPEAT), BORDER_COLOR{ 0,0,0,0 },
        MIN_FILTER(GL_NEAREST), MAG_FILTER(GL_LINEAR)
    {}
    inline void SetBorderColor(float r, float g, float b, float a) 
    {
        BORDER_COLOR[0] = r;
        BORDER_COLOR[1] = g;
        BORDER_COLOR[2] = b;
        BORDER_COLOR[3] = a;
    }
    uint32_t WRAP_S;
    uint32_t WRAP_T;
    float BORDER_COLOR[4];
    uint32_t MIN_FILTER;
    uint32_t MAG_FILTER;
};

class OpenGLApi
{
public:
    static void SetClearColor(float r, float g, float b, float a);
    static void SetViewport(int x, int y, int width, int height);
    static void EnableDepthTest();
    static void ClearDepthBuffer();
    static void ClearColorBuffer();
    static void DrawElements(const VertexArray& va,const IndexBuffer& ib);
    static void SetTexture2DConfig(const Texture2DConfig& config);
    static void ActivateTexture(size_t index);
};