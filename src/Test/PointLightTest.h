#pragma once
#include "Test.h"
#include "Render/OpenGLApi.h"
#include <GLFW/glfw3.h>
#include <assert.h>
#include "Render/Shader.h"
#include <memory>
#include "Render/VertexArray.h"
#include "Render/VertexBuffer.h"
#include "Render/IndexBuffer.h"
#include "Render/Texture2D.h"

class PointLightTest :public Test
{
public:
    PointLightTest();
    ~PointLightTest();
    void OnRender()override;
    void OnImGuiRender()override;
private:
    std::shared_ptr<IndexBuffer> m_IB;
    std::shared_ptr<VertexBuffer> m_VB;
    std::shared_ptr<VertexArray> m_VA;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture2D> m_DiffuseTexture;
    std::shared_ptr<Texture2D> m_SpecularTexture;


    std::shared_ptr<IndexBuffer> m_LightIB;
    std::shared_ptr<VertexBuffer> m_LightVB;
    std::shared_ptr<VertexArray> m_LightVA;
    std::shared_ptr<Shader> m_LightShader;

    float m_RotateX = 0;
    float m_RotateY = 0;
    float m_RotateZ = 0;
    float m_LightX = 0;
    float m_LightY = 0;
    float m_LightZ = 0;
    float m_PosX = 0;
    float m_PosY = 0;
    float m_PosZ = 0;
    float m_Scale = 1;
    float m_CameraX = 0;
    float m_CameraY = 0;
    float m_CameraZ = 0;
private:
    void DrawBox();
    void DrawLight();
};