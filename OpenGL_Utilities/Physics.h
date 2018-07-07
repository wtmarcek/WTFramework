#pragma once
#include "Rectangle.h"
#include "Circle.h"


bool CollisionCircleCircle(const Circle& c1, const Circle& c2);
bool CollisionRectRect(const Rectangle& rect1, const Rectangle& rect2);
bool CollisionRectCircle(const Rectangle& rect, const Circle& circle);