#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	virtual void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	virtual void Clear() const;
};