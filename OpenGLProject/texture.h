#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>//c++ string, string.h is for c
#include <GL/glew.h>

class Texture {
public:
	//constructor
	Texture(const std::string& fileName);
	//methods
	void Bind(unsigned int unit); //bind n textures, limit=0:32

	//deconstructor
	virtual ~Texture();
protected:
private:
	Texture(const Texture& other) {}
	void operator=(const Texture& other){}
	
	GLuint m_texture;
};

#endif //TEXTURE_H