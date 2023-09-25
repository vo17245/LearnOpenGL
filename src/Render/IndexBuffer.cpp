#include "IndexBuffer.h"
#include "OpenGLApi.h"

IndexBuffer::IndexBuffer(uint32_t* buf, size_t count)
    :m_Count(count)
{
    GLCall(glGenBuffers(1, &m_RendererId));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(uint32_t), buf, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererId));
}

void IndexBuffer::Bind()const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
}

void IndexBuffer::Unbind()const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
