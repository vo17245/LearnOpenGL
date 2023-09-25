#include "Application.h"

#include <iostream>
#include "Render/Math.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include "Render/VertexBufferLayout.h"
#include "Render/Renderer.h"
#include "Render/Camera.h"
#include "Test/ParallelLightTest.h"
#include "Test/TestMenu.h"
#include "Test/PointLightTest.h"

Application::Application()
{
    auto testMenu = std::make_unique<TestMenu>();
    testMenu->RegisterTest("ParallelLight", []() {return std::make_unique<ParallelLightTest>();});
    testMenu->RegisterTest("PointLight", []() {return std::make_unique<PointLightTest>();});
    m_Test = std::move(testMenu);
}

void Application::InitWindow()
{
    /* Initialize the library */
    assert(glfwInit() && "glfwInit failed");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    m_Window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
        assert(false && "glfw create window failed");
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowSizeCallback(m_Window, WindowSizeCallback);
}
void Application::InitGLEW()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;;
        assert(false);
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
}
void Application::InitImGui()
{
    // init imgui
    IMGUI_CHECKVERSION();
    ImGuiContext* imguiContext = ImGui::CreateContext();
    ImGui::SetCurrentContext(imguiContext);
    ImGuiIO& io = ImGui::GetIO(); //(void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}



void Application::OnRender()
{
    m_Test->OnRender();
}
void Application::OnImGuiRender()
{
    m_Test->OnImGuiRender();
}
void Application::Run()
{
    //draw
    OpenGLApi::SetClearColor(0.4, 0.5, 0.6, 1.0);
    OpenGLApi::EnableDepthTest();

    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_Window))
    {
        /* Render here */
        OpenGLApi::ClearColorBuffer();
        OpenGLApi::ClearDepthBuffer();
        OnRender();
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        OnImGuiRender();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        /* Swap front and back buffers */
        glfwSwapBuffers(m_Window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}

void Application::WindowSizeCallback(GLFWwindow* window, int width, int height)
{
    int a = width < height ? width : height;
    //OpenGLApi::SetViewport(-1 * a * 9 / 2, -1 * a * 9 / 2, a * 10, a * 10);
    OpenGLApi::SetViewport(0,0,a,a);
}
