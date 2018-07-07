#pragma once
#include "Vec2.h"

class Polygon2D
{
protected:
	Vec2 center;

public:
	Polygon2D(Vec2 center);
	
	Vec2 GetCenter() const;
	void SetCenter(const Vec2 position);
	
};

