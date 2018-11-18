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

	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererID;
};

