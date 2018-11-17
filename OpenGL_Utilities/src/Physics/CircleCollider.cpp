#include "CircleCollider.h"


CircleCollider::CircleCollider(Circle circle) : circle(circle)
{}

Circle & CircleCollider::GetCircle()
{
	return circle;
}


