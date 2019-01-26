#include "Box.h"

Box::Box(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

void Box::SetWidth(float width)
{
	m_Width = width;
}

void Box::SetHeight(float height)
{
	m_Height = height;
}

float Box::GetWidth() const
{
	return m_Width;
}

float Box::GetHeight() const
{
	return m_Height;
}