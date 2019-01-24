#pragma once
#include "wtfpch.h"
#include "SceneObjects/SceneObject.h"


class Scene
{
public:
	Scene();

	void OnStart();
	void OnTick();
	void OnRender();

	void AddSceneObject(SceneObject* obj);
	void RemoveSceneObject(SceneObject* obj);

	const Camera* GetCamera() const;
private:
	std::vector<SceneObject*> m_SceneObjects;
	std::unique_ptr<Camera> m_Camera;
};