#pragma once
#include <string>
#include "Image/Image.h"

class Texture2D
{
public:
	Texture2D(const std::string& path,uint32_t slot);
	Texture2D(const Image& image, uint32_t slot);
	~Texture2D();
	void Bind();
	void Unbind();
	void SetSlot(uint32_t slot);
	inline const uint32_t GetSlot()const { return m_Slot; }
	
private:
	uint32_t m_RendererId;
	uint32_t m_Slot;
};