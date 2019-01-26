#pragma once
#include "SceneObjects/Transform.h"
#include "Renderer/SpriteRenderer.h"
#include "Physics\BoxCollider.h"


static unsigned int s_SceneObjectsCounter = 0;

class SceneObject
{
public:
	SceneObject(const Camera& camera, Texture& texture, Shader& shader);
	virtual ~SceneObject();

	virtual void Update(float dt);

	//void OnCollisionEnter(BoxCollider& collider);

	Transform& GetTransform() const;
	SpriteRenderer& GetRenderer() const;
	const unsigned int GetID() const;
protected:
	std::unique_ptr<Transform> m_Transform;
	std::unique_ptr<SpriteRenderer> m_SpriteRenderer;

	unsigned int m_ID;
};