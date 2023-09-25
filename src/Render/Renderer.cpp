#include "Renderer.h"
#include "OpenGLApi.h"
Camera Renderer::s_Camera;
void Renderer::BeginScene(const Camera& camera)
{
	s_Camera = camera;
}

void Renderer::Submit(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	shader.SetMat4f("u_View", s_Camera.GetView());
	shader.SetMat4f("u_Projection", s_Camera.GetProjection());
	OpenGLApi::DrawElements(va, ib);
}
