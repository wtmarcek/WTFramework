#include "Collider2D.h"


Vec2 Collider2D::GetCenter() const
{
	return center;
}

bool Collider2D::GetActive() const
{
	return isActive;
}

void Collider2D::SetCenter(const Vec2 position)
{
	center = position;
}

void Collider2D::SetActive(const bool isActive)
{
	this->isActive = isActive;
}
