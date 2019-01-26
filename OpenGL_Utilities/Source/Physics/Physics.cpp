#pragma once
#include "Physics.h"
#include "SceneObjects\SceneObject.h"


BoxCollider* Physics::CheckCollision(BoxCollider* A)
{
	//for (auto it = m_Colliders.begin(); it != m_Colliders.end(); it++)
	//{
	//	Transform& A_trans = A->GetSceneObject().GetTransform();
	//	glm::vec3 A_pos = (*A).GetSceneObject().GetTransform().GetPosition();
	//
	//	BoxCollider* B = *it;
	//	SceneObject& B_obj = B->GetSceneObject();
	//	Transform& B_trans = B->GetSceneObject().GetTransform();
	//	glm::vec3 B_pos = B->GetSceneObject().GetTransform().GetPosition();
	//	
	//	if (A_pos != B_pos)
	//	{
	//		bool collisionX =
	//			(A_pos.x + A_trans.GetWidth() >= B_pos.x) &&
	//			(B_pos.x + B_trans.GetWidth() >= A_pos.z);
	//
	//		bool collisionZ =
	//			(A_pos.z + A_trans.GetHeight() >= B_pos.z) &&
	//			(B_pos.z + B_trans.GetHeight() >= A_pos.x);
	//
	//		if (collisionX && collisionZ)
	//		{
	//			return B;
	//		}
	//	}
	//}
	return nullptr;
}

void Physics::AddCollider(BoxCollider* collider)
{
	m_Colliders.push_back(collider);
}

void Physics::RemoveCollider(BoxCollider* collider)
{
	for (auto it = m_Colliders.begin(); it != m_Colliders.end(); it++)
	{
		if (*it != collider)
		{
			m_Colliders.erase(it);
		}
	}
}
