#pragma once
class SceneObject;


enum CollisionLayer
{
	Player,
	PickUp,
	Damage
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