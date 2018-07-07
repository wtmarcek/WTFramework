#include "Rectangle.h"


Rectangle::Rectangle(Vec2 center, float width, float height)
	: Polygon2D(center), width(width), height(height)
{}

Vec2 Rectangle::GetSize() const
{
	return Vec2(width, height);
}

Vec2 Rectangle::GetLeftTopVert() const
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;
	return Vec2 (center.x - halfWidth, center.y + halfHeight);
}

Vec2 Rectangle::GetRightBottomVert() const
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;
	return 	Vec2 (center.x + halfWidth, center.y - halfHeight);
}

void Rectangle::SetSize(const float width, const float height)
{
	this->width = width;
	this->height = height;
}
