#include "Circle.h"


Circle::Circle(Vec2 center, float radius) : Polygon2D(center), radius(radius)
{}

float Circle::GetRadius() const
{
	return radius;
}

void Circle::SetRadius(float r)
{
	radius = r;
}
