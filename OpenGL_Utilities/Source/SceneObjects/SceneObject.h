#pragma once
#include "SceneObjects/Transform.h"
#include "Renderer/SpriteRenderer.h"

class BoxCollider;
enum CollisionLayer;

static unsigned int s_SceneObjectsCounter = 0;

class SceneObject
{
public:
	SceneObject(const Camera& camera, Texture& texture, Shader& shader, CollisionLayer layer);
	virtual ~SceneObject();

	virtual void Update(float dt);

	void OnCollisionEnter(BoxCollider& collider);

	Transform& GetTransform() const;
	SpriteRenderer& GetRenderer() const;
	const unsigned int GetID() const;

protected:
	std::unique_ptr<Transform> m_Transform;
	std::unique_ptr<SpriteRenderer> m_SpriteRenderer;
	std::unique_ptr<BoxCollider> m_BoxCollider;

	unsigned int m_ID;
};