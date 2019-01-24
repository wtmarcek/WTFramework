#include "Scene.h"

Scene::Scene()
{
	m_Camera = std::make_unique<Camera>();
}

void Scene::OnStart()
{
}

void Scene::OnTick()
{
}

void Scene::OnRender()
{
	for (auto it = m_SceneObjects.begin(); it != m_SceneObjects.end(); it++)
	{
		(*it)->GetRenderer().Draw();
	}
}

void Scene::AddSceneObject(SceneObject* obj)
{
	m_SceneObjects.emplace_back(obj);
}

void Scene::RemoveSceneObject(SceneObject* obj)
{
	for (auto it = m_SceneObjects.begin(); it != m_SceneObjects.end(); it++)
	{
		if (*it == obj)
		{
			m_SceneObjects.erase(it);
			break;
		}
	}
}

const Camera* Scene::GetCamera() const
{
	return m_Camera.get();
}
