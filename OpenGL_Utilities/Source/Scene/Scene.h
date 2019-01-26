#pragma once
#include "wtfpch.h"
#include "SceneObjects/SceneObject.h"

static float DELTA_TIME = 0;

class Scene
{
public:
	Scene();

	void OnStart();
	void OnTick(float dt);
	void OnRender();

	void AddSceneObject(SceneObject* obj);
	void RemoveSceneObject(SceneObject* obj);

	const Camera* GetCamera() const;
private:
	std::vector<SceneObject*> m_SceneObjects;
	std::unique_ptr<Camera> m_Camera;
};