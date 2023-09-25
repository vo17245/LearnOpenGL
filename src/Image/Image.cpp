#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <assert.h>

Image::Image(const std::string& path)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_Channel, 0);
    assert(data != nullptr&&"Failed to load image");
    m_Data = data;
}


Image::~Image()
{
    STBI_FREE(m_Data);
}
