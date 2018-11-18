#pragma once
#include "GL/glew.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "OpenGLDebug.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind();
	void Unbind();
private:
	unsigned int m_RendererID;
};

