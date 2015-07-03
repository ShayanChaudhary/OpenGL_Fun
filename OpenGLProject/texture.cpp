#include "texture.h"
#include <assert.h>
#include <iostream>

#define STBI_ASSERT(x) 
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string& fileName)
{
	int width, height, numComponents;
	//load texture
	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	if (imageData == NULL)
		std::cerr << "Texture: loading image failed!:  " << std::endl;

	//generate some space for 1 texture
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//set texture properties - let texture wrap/repeat if we run out.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//when we require to minimise the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//when magnification is required
	
	//specify a 2d texture image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	//free from memory
	stbi_image_free(imageData);

}

Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}
void Texture::Bind(unsigned int units)
{
	assert(units >= 0 && units <= 31); //check units is not bigger then 31, as OpenGL has only 31 texture units

	glActiveTexture(GL_TEXTURE0 + units);//change which texture OpenGl is working with
	glBindTexture(GL_TEXTURE_2D, m_texture);

}