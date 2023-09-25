#pragma once
#include "Render/OpenGLApi.h"
#include <GLFW/glfw3.h>
#include <assert.h>
#include "Render/Shader.h"
#include <memory>
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/IndexBuffer.h"
#include "Render/Texture2D.h"
#include "Test/Test.h"

class Application
{
public:
    Application();
    void InitWindow();
    void InitGLEW();
    void InitImGui();
    void OnRender();
    void OnImGuiRender();
    void Run();
private:
    //event
    static void WindowSizeCallback(GLFWwindow* window, int width, int height);


private:
    GLFWwindow* m_Window;
private:
    std::unique_ptr<Test> m_Test;
};