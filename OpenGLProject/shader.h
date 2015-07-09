#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include "transform.h"

/*Implements Vertex and Fragment Shader*/
class Shader
{
public:
	//constructor
	Shader(const std::string& fileName);
	//methods
	void Bind();
    void Update(const Transform& transform);

	//deconstructor
	virtual ~Shader();
protected:
private:

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

    enum {
        TRANSFORM_U,
        NUM_UNIFORMS
    };


	static const unsigned int NUM_SHADERS = 2;//2 shaders vertex & fragment
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif //SHADER_H

