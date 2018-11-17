#include "Primitive.h"

Primitive::Primitive(Vec2 position) : position(position)
{}

Vec2 Primitive::GetPosition() const
{
	return position;
}
