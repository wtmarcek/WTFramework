#pragma once
#include "Polygon2D.h"


class Circle : public Polygon2D
{
protected:
	float radius;

public:
	Circle(Vec2 center, float radius);

	float GetRadius() const;
	void SetRadius(float r);
};

