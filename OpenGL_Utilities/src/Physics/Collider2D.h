#pragma once
#include <Utility>
#include <vector>
#include <memory>
#include "MathUtilities/Vec2.h"
#include "Circle.h"
#include "Rectangle.h"

class Collider2D
{
protected:
	Vec2 center;
	bool isActive = true;

public:
	//virtual std::vector<Collider2D*> FindCollisions(std::vector<Collider2D> colliders) const = 0;
	Vec2 GetCenter() const;
	bool GetActive() const;
	virtual void SetCenter(const Vec2 position);
	void SetActive(const bool isActive);
protected:

};

