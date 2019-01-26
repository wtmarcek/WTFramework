#include "ThrowingObject.h"

ThrowingObject::ThrowingObject(const Camera & camera, Texture & texture, Shader & shader, CollisionLayer layer)
	: SceneObject(camera, texture, shader, layer)
{
	m_Force = glm::vec3(0.0f);
}

ThrowingObject::~ThrowingObject()
{
}

void ThrowingObject::Update(float dt)
{
	glm::vec3 newPos = dt * m_Force + m_Transform->GetPosition();
	m_Transform->SetPosition(newPos);
}

void ThrowingObject::SetForce(glm::vec3 newForce)
{
	m_Force = newForce;
}

