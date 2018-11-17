#include "Circle.h"


Circle::Circle(Vec2 position, float radius) : Primitive(position), radius(radius)
{}

void Circle::Draw() const
{
	//TODO : IMPLEMENT
}

float Circle::GetRadius() const
{
	return radius;
}

void Circle::SetPosition(const Vec2 position)
{
	//TODO : IMPLEMENT
}

void Circle::SetRadius(float r)
{
	radius = r;
}
