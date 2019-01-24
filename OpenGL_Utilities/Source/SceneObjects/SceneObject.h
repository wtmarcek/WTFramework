#pragma once
#include "wtfpch.h"
#include "Transform.h"
#include "SpriteRenderer.h"

static unsigned int s_SceneObjectsCounter = 0;

class SceneObject
{
public:
	SceneObject(const Camera& camera, Texture& texture, Shader& shader);
	~SceneObject();

	Transform& GetTransform() const;
	SpriteRenderer& GetRenderer() const;
	const unsigned int GetID() const;
private:
	std::unique_ptr<Transform> m_Transform;
	std::unique_ptr<SpriteRenderer> m_SpriteRenderer;

	unsigned int m_ID;
};