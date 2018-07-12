#include <cmath>
#include <algorithm>
#include "Physics.h"
#include "MathUtilities.h"


bool CollisionCircleCircle(const Circle & c1, const Circle & c2)
{
	float radiusSum = c1.GetRadius() + c2.GetRadius();
	float centersDist = c1.GetPosition().GetDistance(c2.GetPosition());
	if (centersDist <= radiusSum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionRectRect(const Rectangle & rect1, const Rectangle & rect2)
{
	float centersDistX = abs(rect2.GetPosition().x - rect1.GetPosition().x);
	float centersDistY = abs(rect2.GetPosition().y - rect1.GetPosition().y);
	if (centersDistX <= rect1.GetSize().x / 2 + rect2.GetSize().x / 2 &&
		centersDistY <= rect1.GetSize().y / 2 + rect2.GetSize().y / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionRectCircle(const Rectangle & rect, const Circle & circle)
{
	bool isColliding = false;
	Vec2 rectHalfSize = Vec2(rect.GetSize().x/2.0f, rect.GetSize().y/2.0f);
	float Ax = Clamp(abs(rect.GetPosition().x - circle.GetPosition().x) / rectHalfSize.x, 0.0f, rectHalfSize.x);
	float Ay = Clamp(abs(rect.GetPosition().y - circle.GetPosition().y) / rectHalfSize.y, 0.0f, rectHalfSize.y);
	Vec2 A(Ax, Ay);
	if (A.GetDistance(circle.GetPosition()) <= circle.GetRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}
