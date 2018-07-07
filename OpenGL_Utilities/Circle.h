#pragma once
#include "Primitive.h"


class Circle : public Primitive
{
protected:
	float radius;

public:
	Circle(Vec2 center, float radius);
	
	void Draw() const override;

	float GetRadius() const;
	void SetPosition(const Vec2 position) override;
	void SetRadius(float r);
};

