#pragma once
#include "Physics.h"

BoxCollider* Physics::CheckCollision(BoxCollider* A)
{
	for (auto it = m_Colliders.begin(); it != m_Colliders.end(); it++)
	{
		glm::vec3 A_pos = (*A).GetSceneObject().GetTransform().GetPosition();
		Box& A_box = (*A).GetBox();

		BoxCollider& B = **it;
		glm::vec3 B_pos = B.GetSceneObject().GetTransform().GetPosition();
		Box& B_box = B.GetBox();
		
		if (A_pos != B_pos)
		{
			bool collisionX =
				(A_pos.x + A_box.GetWidth() >= B_pos.x) &&
				(B_pos.x + B_box.GetWidth() >= A_pos.z);

			bool collisionZ =
				(A_pos.z + A_box.GetHeight() >= B_pos.z) &&
				(B_pos.z + B_box.GetHeight() >= A_pos.x);

			if (collisionX && collisionZ)
			{
				return &B;
			}
		}
	}
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
