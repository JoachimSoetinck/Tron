#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"


using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

void dae::Scene::DeleteObjects()
{
	m_Objects.clear();
}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
	
}

void Scene::Update()
{
	for(auto& object : m_Objects)
	{
		object->Update();
	}

}

void dae::Scene::FixedUpdate()
{
	for (const auto& object : m_Objects)
	{
		object->FixedUpdate();
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();
	}
}

void dae::Scene::Remove(std::shared_ptr<GameObject> object)
{
	m_Objects.erase(std::remove(m_Objects.begin(), m_Objects.end(), object));
}



