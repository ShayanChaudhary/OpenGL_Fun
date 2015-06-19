#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

/*Implements Vertex and Fragment Shader*/
class Shader
{
public:
	//constructor
	Shader(const std::string& fileName);
	//methods
	void Bind();

	//deconstructor 
	virtual ~Shader();
protected:
private:
	
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	static const unsigned int NUM_SHADERS = 2;//2 shaders vertex & fragment
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];

};

#endif //SHADER_H

