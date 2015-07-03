#ifndef MESH_H
#define MESH_H

//include OpenGL maths library
#include <glm/glm.hpp>
#include <GL/glew.h>


//Single vertex class, can be made into a struct 
//but its class as I may extend it later on.
class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& textCoord) {
		this->pos = pos;
		this->texCoord = textCoord;
	}

	inline glm::vec3* GetPos() { return &pos; }
	inline glm::vec2* GetTexCoord() { return &texCoord; }
protected:
private:
	glm::vec3 pos;
	glm::vec2 texCoord;

};



/*This class takes some model data and send it to gpu*/
class Mesh
{
public:
	//constructor - takes list of vertices and num of verticies.
	Mesh(Vertex* vertices, unsigned int numVerticies);
	//methods
	void Draw();

	//deconstructor
	virtual ~Mesh();
protected:
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	enum{POSITION_VB, 
		TEXTCOORD_VB,
		NUM_BUFFERS};

	//GL unsigned integer - used for better cross platform compatibility
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;

};

#endif // MESH_H
