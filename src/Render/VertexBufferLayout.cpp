#include "VertexBufferLayout.h"
#include "OpenGLApi.h"

void VertexBufferLayout::Use()
{
	for (size_t i=0;i<m_Elements.size();i++)
	{
		auto& element = m_Elements[i];
		if (element.m_Type == VertexBufferElementType::FLOAT)
		{
			glVertexAttribPointer(i, element.m_Count, (int32_t)element.m_Type, GL_FALSE, m_Stride, (const void*)element.m_Offset);
			glEnableVertexAttribArray(i);
		}
		else
		{
			assert(false && "Unknown VertexBufferElement Type");
		}
	}
}
