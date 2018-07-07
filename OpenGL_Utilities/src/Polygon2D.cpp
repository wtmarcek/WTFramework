#include "Polygon2D.h"


Polygon2D::Polygon2D(const Vec2 center)
{
	SetCenter(center);
}

Vec2 Polygon2D::GetCenter() const
{	
	return center;
}

void Polygon2D::SetCenter(const Vec2 position)
{
	center = position;
}
