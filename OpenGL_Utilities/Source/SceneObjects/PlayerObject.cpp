#pragma once
#include "PlayerObject.h"


PlayerObject::PlayerObject(const Camera & camera, Texture & texture, Shader & shader, CollisionLayer layer, GLFWwindow* window)
	: SceneObject(camera, texture, shader, layer)
{
	m_Window = window;
}

void PlayerObject::Update(float dt)
{
	int state = glfwGetKey(m_Window, GLFW_KEY_W);
	if(state == GLFW_PRESS)
		MoveForward(1.0f * dt);
	
	state = glfwGetKey(m_Window, GLFW_KEY_S);
	if (state == GLFW_PRESS)
		MoveForward(-1.0f * dt);

	state = glfwGetKey(m_Window, GLFW_KEY_D);
	if (state == GLFW_PRESS)
		MoveRight(1.0f * dt);

	state = glfwGetKey(m_Window, GLFW_KEY_A);
	if (state == GLFW_PRESS)
		MoveRight(-1.0f * dt);
}

void PlayerObject::MoveForward(float speed)
{
	glm::vec3 newPos = m_Transform->GetPosition() + glm::vec3(0.0f, speed, 0.0f);
	m_Transform->SetPosition(newPos);
}

void PlayerObject::MoveRight(float speed)
{
	glm::vec3 newPos = m_Transform->GetPosition() + glm::vec3(speed, 0.0f, 0.0f);
	m_Transform->SetPosition(newPos);
}
