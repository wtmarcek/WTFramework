#pragma once
#include "SceneObjects\Transform.h"


class Box
{
public:
	Box(float width, float height);

	void SetWidth(float width);
	void SetHeight(float height);

	float GetWidth() const;
	float GetHeight() const;

private:
	float m_Width, m_Height;
};