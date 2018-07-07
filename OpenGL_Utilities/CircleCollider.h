#pragma once
#include "Circle.h"
#include "Collider2D.h"

class CircleCollider : public Collider2D
{
	Circle circle;

public:
	CircleCollider(Circle circle);
	
	Circle& GetCircle();
};

