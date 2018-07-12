#include "RectCollider.h"


RectCollider::RectCollider(const Rectangle rect) : rect(rect)
{}

RectCollider::~RectCollider()
{}

Rectangle & RectCollider::GetRect()
{
	return rect;
}
void RectCollider::SetCenter(const Vec2 position)
{
	//TODO : IMPLEMENT
}
//
//std::vector<Vec2> RectCollider::GetVertices() const
//{
//	return rect.GetVertices();
//}
//
//Vec2 RectCollider::GetCenter() const
//{
//	return rect.GetCenter();
//}
//
//void RectCollider::SetCenter(const Vec2 position)
//{
//	rect.SetCenter(position);
//}
//
//void RectCollider::SetSize(int width, int height)
//{
//	rect.SetSize(width, height);
//}



