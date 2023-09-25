#include "ParallelLightTest.h"
#include "Render/Renderer.h"
#include "Render/Math.h"

ParallelLightTest::ParallelLightTest()
{
    float vbData[288] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };


    uint32_t ibData[36] = {
        0,1,2,
        3,4,5,
        6,7,8,
        9,10,11,
        12,13,14,
        15,16,17,
        18,19,20,
        21,22,23,
        24,25,26,
        27,28,29,
        30,31,32,
        33,34,35,
    };
    // 创建材质贴图
    m_DiffuseTexture = std::make_shared<Texture2D>("D:/dev/LearnOpenGL/res/texture/container2.png", 0);
    m_SpecularTexture = std::make_shared<Texture2D>("D:/dev/LearnOpenGL/res/texture/container2_specular.png", 1);

    //创建 vertex array
    m_VA = std::make_shared<VertexArray>();
    //创建vertex buffer
    m_VB = std::make_shared<VertexBuffer>(vbData, sizeof(float) * 288);
    //指定布局
    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    layout.Use();
    //创建index buffer
    m_IB = std::make_shared<IndexBuffer>(ibData, 36);
    //加载编译shader
    m_Shader = std::make_shared<Shader>("D:/dev/LearnOpenGL/res/shader/light.shader");
}

ParallelLightTest::~ParallelLightTest()
{
}

void ParallelLightTest::OnRender()
{
    Eigen::Matrix4f view = Math::Identity();
    Eigen::Matrix4f projection = Math::Perspective(-0.1, -1, 1, -1, 1, -1);
    Camera camera(view, projection);
    Renderer::BeginScene(camera);
    DrawBox();

    Renderer::EndScene();
}

void ParallelLightTest::OnImGuiRender()
{
    ImGui::Begin("rotate");
    ImGui::SliderFloat("x", &m_RotateX, -6.28, 6.28);
    ImGui::SliderFloat("y", &m_RotateY, -6.28, 6.28);
    ImGui::SliderFloat("z", &m_RotateZ, -6.28, 6.28);
    ImGui::End();

    ImGui::Begin("pos");
    ImGui::SliderFloat("x", &m_PosX, -1, 1);
    ImGui::SliderFloat("y", &m_PosY, -1, 1);
    ImGui::SliderFloat("z", &m_PosZ, -1, 1);
    ImGui::End();

    ImGui::Begin("scale");
    ImGui::SliderFloat("box_scale", &m_Scale, 0, 1);
    ImGui::End();
}

void ParallelLightTest::DrawBox()
{
    //绘制盒子
    m_Shader->Bind();
    // 光源
    m_Shader->SetVec3f("u_LightColor", Eigen::Vector3f(1, 1, 1));
    //m_Shader->SetVec3f("u_LightPos", Eigen::Vector3f(m_LightX, m_LightY, m_LightZ));
    m_Shader->SetVec3f("u_LightDirection", Eigen::Vector3f(0, -1, 0));
    // mvp
    Eigen::Matrix4f model = Math::Identity();
    model = Math::Scale(m_Scale, m_Scale, m_Scale) * model;
    model = Math::RotateX(m_RotateX) * model;
    model = Math::RotateY(m_RotateY) * model;
    model = Math::RotateZ(m_RotateZ) * model;
    model = Math::Move(m_PosX, m_PosY, m_PosZ) * model;
    m_Shader->SetMat4f("u_Model", model);
    // material
    m_Shader->SetInt("material.diffuse", 0);
    m_Shader->SetInt("material.specular", 1);
    m_Shader->SetFloat("material.shininess", 0.2);

    // draw
    Renderer::Submit(*m_VA, *m_IB, *m_Shader);
}

