#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Vec2.h"


class Primitive
{
protected:
	Vec2 position;
	std::vector<float> vertexPos;
	std::vector<unsigned int> indices;

public:	
	Primitive(Vec2 position);
	
	virtual void Draw() const = 0;
	virtual void SetPosition(const Vec2 position) = 0;

	Vec2 GetPosition() const;
};

