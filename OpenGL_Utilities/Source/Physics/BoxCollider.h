#pragma once
#include "Geometry\Box.h"
#include "SceneObjects\SceneObject.h"
//#include "Physics.h"


enum ColliderLayer
{
	Player,
	PickUp,
	Weapon
};

class BoxCollider
{
public:
	BoxCollider(float width, float height, ColliderLayer layer, SceneObject* sceneObj);
	~BoxCollider();

	void OnUpdate();

	//SceneObject& GetSceneObject() const;
	ColliderLayer GetLayer() const;
	Box& GetBox() const;
private:
	const SceneObject* m_SceneObject;
	std::unique_ptr<Box> m_Box;
	ColliderLayer m_Layer;

	//Physics* physics;
};