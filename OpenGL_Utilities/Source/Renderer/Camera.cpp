#include "Camera.h"

Camera::Camera()
	: m_Projection(glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, -1000.0f, 100.0f)),
	m_View(glm::mat4(1.0f))
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetProjection() const
{
	return m_Projection;
}

glm::mat4 Camera::GetView() const
{
	return m_View;
}
