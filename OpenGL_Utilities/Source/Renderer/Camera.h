#pragma once

#include "wtfpch.h"

class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 GetProjection() const;
	glm::mat4 GetView() const;

private:
	glm::mat4 m_Projection;
	glm::mat4 m_View;
};