#include "mesh.h"
#include <vector>

Mesh::Mesh(Vertex* vertices, unsigned int numVerticies)
{
	m_drawCount = numVerticies;
	glGenVertexArrays(1, &m_vertexArrayObject);
	//once bound, any operation that effects an vertex array object will effect this object
	glBindVertexArray(m_vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	//reserve atleast n verticies worth of places in memory.
	positions.reserve(numVerticies);
	texCoords.reserve(numVerticies);
	//fill these vectors with relavent data.
	for (unsigned int i = 0; i < numVerticies; i++){
		positions.push_back(*vertices[i].GetPos());
		texCoords.push_back(*vertices[i].GetTexCoord());
	}

	//take data and move it to gpu, generate buffer -> bind buffer -> move data
	//generate buffer
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	
	//setup verticies position array buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
	//tell GL how to make sense of data, by defining the vertex attributes
	//we only have one attribute: vec4 pos
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//stride=how much to skip, last par = where to start
	

	//setup texture coord buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXTCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);

}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}


void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);//bind

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);//draw

	glBindVertexArray(0);//unbind
}