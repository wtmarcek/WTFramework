#pragma once
#include <vector>
#include "Primitive.h"

class Rectangle : public Primitive
{
protected:
	float width;
	float height;

public:
	Rectangle(Vec2 position, float width, float height);

	void Draw() const override;

	Vec2 GetSize() const;
	Vec2 GetLeftTopVert() const;
	Vec2 GetRightBottomVert() const;
	void SetSize(const float width, const float height);
	void SetPosition(const Vec2 position) override;

};

