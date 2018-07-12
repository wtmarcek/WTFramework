#include "Rectangle.h"


Rectangle::Rectangle(Vec2 position, float width, float height)
	: Primitive(position), width(width), height(height)
{}

Vec2 Rectangle::GetSize() const
{
	return Vec2(width, height);
}

Vec2 Rectangle::GetLeftTopVert() const
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;
	return Vec2 (position.x - halfWidth, position.y + halfHeight);
}

Vec2 Rectangle::GetRightBottomVert() const
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;
	return 	Vec2 (position.x + halfWidth, position.y - halfHeight);
}

void Rectangle::SetSize(const float width, const float height)
{
	this->width = width;
	this->height = height;
}

void Rectangle::SetPosition(const Vec2 position)
{
	//TODO : IMPLEMENT
}

void Rectangle::Draw() const
{
	//TODO : IMPLEMENT
}
