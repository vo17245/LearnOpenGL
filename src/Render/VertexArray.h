#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind()const;
	void Unbind()const;
	void SetData(VertexBuffer& vb,VertexBufferLayout& vbl);
private:
	uint32_t m_RendererId;
};