#include "Triangle.h"



Triangle::Triangle(Vec2 position, Vec2 vertices[3]) : Primitive(position)
{
	vertexPos.reserve(6);
	for (int i = 0; i < 3; i++)
	{
		vertexPos.emplace_back(vertices[i].x);
		vertexPos.emplace_back(vertices[i].y);
	}
	indices.reserve(3);
	indices = { 0,1,2 };
}

void Triangle::Draw() const
{
	unsigned int posBuffer;
	glGenBuffers(1, &posBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, &vertexPos[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	
	unsigned int indicesBuffer;
	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &indices[0], GL_STATIC_DRAW);
}

void Triangle::SetPosition(const Vec2 position)
{
	//TODO : IMPLEMENT
}
