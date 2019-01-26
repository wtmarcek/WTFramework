#include "Transform.h"

Transform::Transform()
{
	m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

void Transform::SetPosition(glm::vec3 pos)
{
	if (pos.x < 100.0f && pos.x > -100.0f)
	{
		m_Position.x = pos.x;
	}
	if (pos.y < 100.0f && pos.y > -100.0f)
	{
		m_Position.y = pos.y;
	}
}

void Transform::SetRotation(glm::vec3 rot)
{
	m_Rotation = rot;
}

void Transform::SetScale(glm::vec3 scale)
{
	m_Scale = scale;
}

const glm::vec3 Transform::GetPosition() const
{
	return m_Position;
}

const glm::vec3 Transform::GetRotation() const
{
	return m_Rotation;
}

const glm::vec3 Transform::GetScale() const
{
	return m_Scale;
}

const glm::mat4 Transform::GetTransformationMatrix() const
{
	return glm::scale(
		glm::rotate(
		glm::translate(
		glm::mat4(1.0f), m_Position), m_Rotation.y, glm::vec3(0.0f, 0.0f, 1.0f)), m_Scale);
}

float Transform::GetWidth()
{
	return m_Scale.x ;
}

float Transform::GetHeight()
{
	return m_Scale.y;
}