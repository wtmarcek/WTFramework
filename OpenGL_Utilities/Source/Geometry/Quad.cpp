#include "Quad.h"

Quad::Quad()
{

	m_Vertices =
	{
		//Vertices				//UV
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,		//0
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f,		//1
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f,		//2
		-0.5f,  0.5f, 0.0f,		0.0f, 1.0f 		//3
	};

	m_Indices =
	{
		0,1,2,
		2,3,0
	};
}

Quad::~Quad()
{
	m_Vertices.clear();
	m_Vertices.shrink_to_fit();
}

