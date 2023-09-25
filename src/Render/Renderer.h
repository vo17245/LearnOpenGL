#pragma once
#include "Camera.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
private:
	static Camera s_Camera;
public:
	static void BeginScene(const Camera& camera);
	static void Submit(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	static void EndScene(){}
};