#include "BoxCollider.h"


BoxCollider::BoxCollider(float width, float height, ColliderLayer layer, SceneObject* sceneObj)
	: m_SceneObject(sceneObj), m_Layer(layer)
{
	m_Box = std::make_unique<Box>(width, height);
	
	//Physics* physics = physics->GetInstance();	
	//physics->AddCollider(this);
}

BoxCollider::~BoxCollider()
{
	//Physics* physics = physics->GetInstance();
	//physics->RemoveCollider(this);
}

void BoxCollider::OnUpdate()
{
	//BoxCollider* other = physics->CheckCollision(*this);
	//if (other != nullptr)
	//{
	//	m_SceneObject.OnCollisionEnter(*other);
	//}
}

//SceneObject & BoxCollider::GetSceneObject() const
//{
//	return m_SceneObject;
//}

ColliderLayer BoxCollider::GetLayer() const
{
	return m_Layer;
}

Box & BoxCollider::GetBox() const
{
	return *m_Box;
}
