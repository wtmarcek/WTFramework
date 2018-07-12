#pragma once
#include <vector>
#include "Primitive.h"
#include "Vec2.h"

class Polygon2D : Primitive
{
protected:

public:
	Polygon2D(Vec2 center);
	
	void SetPosition(const Vec2 position) override;
	void Draw() const override;
	
};

