#include "mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVerticies)
{
	m_drawCount = numVerticies;
	glGenVertexArrays(1, &m_vertexArrayObject);
	//once bound, any operation that effects an vertex array object will effect this object
	glBindVertexArray(m_vertexArrayObject);

	//take data and move it to gpu, generate buffer -> bind buffer -> move data
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	//tell GL how to make sense of data, by defining the vertex attributes
	//we only have one attribute: vec4 pos
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);//stride=how much to skip, last par = where to start

	//unbind object
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