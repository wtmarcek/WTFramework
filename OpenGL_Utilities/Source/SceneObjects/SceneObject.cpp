#include "SceneObject.h"


SceneObject::SceneObject(const Camera& camera, Texture& texture, Shader& shader)
{
	m_ID = s_SceneObjectsCounter++;	
	m_Transform = std::make_unique<Transform>();
	m_SpriteRenderer = std::make_unique<SpriteRenderer>(camera, texture, shader, *m_Transform);
}

SceneObject::~SceneObject()
{
	s_SceneObjectsCounter--;
}

void SceneObject::Update(float dt)
{
}

void SceneObject::OnCollisionEnter(BoxCollider & collider)
{
	//std::cout << "collision detected: " << std::endl;
}

void SceneObject::kutas(BoxCollider & b)
{

}

SpriteRenderer& SceneObject::GetRenderer() const
{
	return *m_SpriteRenderer;
}

const unsigned int SceneObject::GetID() const
{
	return m_ID;
}

Transform& SceneObject::GetTransform() const
{
	return *m_Transform;
}
