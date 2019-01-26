#pragma once
#include "BoxCollider.h"
#include "Physics.h"
#include "SceneObjects\SceneObject.h"


BoxCollider::BoxCollider(SceneObject & sceneObject, CollisionLayer layer)
	: m_SceneObject(&sceneObject), Layer(layer)
{
	Physics *physics = physics->GetInstance();
	physics->AddCollider(this);
}

BoxCollider::~BoxCollider()
{
	Physics* physics = physics->GetInstance();
	physics->RemoveCollider(this);
}

void BoxCollider::Update(float dt)
{
	Physics* physics = physics->GetInstance();
	BoxCollider* other = physics->CheckCollision(this);
	
	if (other != nullptr)
	{
		m_SceneObject->OnCollisionEnter(*other);
	}
}

SceneObject & BoxCollider::GetSceneObject() const
{
	return *m_SceneObject;
}
