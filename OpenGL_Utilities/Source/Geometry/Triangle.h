#pragma once
#include "Primitive.h"


class Triangle : public Primitive
{
	

public:
	Triangle(Vec2 position, Vec2 vertices[3]);

	void Draw() const override;

	void SetPosition(const Vec2 position) override;
};

