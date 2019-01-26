#pragma once
class SceneObject;


enum CollisionLayer
{
	Player = 0,
	PickUp = 1,
	Damage = 2
};

class BoxCollider
{
public:
	BoxCollider(SceneObject& sceneObject, CollisionLayer layer);
	~BoxCollider();

	void Update(float dt);

	SceneObject& GetSceneObject() const;
	CollisionLayer Layer;	

private:
	SceneObject* m_SceneObject;
};