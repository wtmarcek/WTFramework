#pragma once
#include "wtfpch.h"


class Transform
{
public:
	Transform();

	void SetPosition(glm::vec3 pos);
	void SetRotation(glm::vec3 rot);
	void SetScale(glm::vec3 scale);
	
	const glm::vec3 GetPosition() const;
	const glm::vec3 GetRotation() const;
	const glm::vec3 GetScale() const;
	const glm::mat4 GetTransformationMatrix() const;
	float GetWidth();
	float GetHeight();

private:
	glm::vec3 m_Position;
	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;
};