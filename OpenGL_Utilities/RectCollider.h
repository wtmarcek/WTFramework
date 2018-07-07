#pragma once
#include <vector>
#include "Collider2D.h"
#include "Rectangle.h"

class RectCollider : public Collider2D
{
protected:
	Rectangle rect;

public:
	RectCollider(const Rectangle rect);
	~RectCollider();

	//std::vector<Collider2D*> FindCollisions(std::vector<Collider2D> collider) const override;
	bool IsColliding(RectCollider& other);
	Rectangle& GetRect();
	//std::vector<Vec2> GetVertices() const;
	//Vec2 GetCenter() const;
	//void SetCenter(const Vec2 position);
	//void SetSize(const int width, const int height);
};

