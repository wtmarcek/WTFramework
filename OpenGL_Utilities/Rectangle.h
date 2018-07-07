#pragma once
#include <vector>
#include "Polygon2D.h"

class Rectangle : public Polygon2D
{
protected:
	float width;
	float height;

public:
	Rectangle(Vec2 center, float width, float height);

	Vec2 GetSize() const;
	Vec2 GetLeftTopVert() const;
	Vec2 GetRightBottomVert() const;
	void SetSize(const float width, const float height);
};

