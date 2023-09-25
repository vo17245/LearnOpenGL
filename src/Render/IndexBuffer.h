#pragma once
#include <stdint.h>
class IndexBuffer
{
public:
	IndexBuffer(uint32_t* buf, size_t count);
	~IndexBuffer();
	void Bind()const;
	void Unbind()const;
	inline const size_t GetCount()const { return m_Count; }
private:
	uint32_t m_RendererId;
	size_t m_Count;
};