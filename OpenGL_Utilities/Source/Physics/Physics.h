#pragma once
#include <vector>
class BoxCollider;

class Physics 
{
	Physics() { }

public:
	static Physics* s_Instance;
	static Physics* GetInstance()
	{
		if (!s_Instance)
			s_Instance = new Physics;
		return s_Instance;
	}
	
	void AddCollider(BoxCollider* collider);	
	void RemoveCollider(BoxCollider* collider);

	BoxCollider* CheckCollision(BoxCollider* A);
		
private:
	std::vector<BoxCollider*> m_Colliders;
};