#pragma once
#include "SceneObject.h"
#include <GLFW\glfw3.h>


class PlayerObject : public SceneObject
{
public:
	PlayerObject(const Camera& camera, Texture& texture, Shader& shader, CollisionLayer layer, GLFWwindow* window);

	void Update(float dt) override;

	void MoveForward(float speed);
	void MoveRight(float speed);

private:
	GLFWwindow* m_Window;
};