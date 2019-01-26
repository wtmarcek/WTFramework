#pragma once

#include "SceneObject.h"
#include "Scene\Scene.h"
enum CollisionLayer;


class ThrowingObject : public SceneObject
{
public:
	ThrowingObject(const Camera& camera, Texture& texture, Shader& shader, CollisionLayer layer);
	~ThrowingObject();

	void Update(float dt) override;

	void SetForce(glm::vec3 newForce);

private:	
	glm::vec3 m_Force;

};