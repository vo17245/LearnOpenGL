#pragma once
#include <stdint.h>
class VertexBuffer
{
public:
	VertexBuffer(void* data,size_t size);
	~VertexBuffer();
	void Bind();
	void Unbind();
private:
	uint32_t m_RendererId;
};