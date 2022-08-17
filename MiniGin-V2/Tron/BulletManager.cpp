#include "BulletManager.h"

#include "Scene.h"
#include "SceneManager.h"

void BulletManager::AddBullet(const std::shared_ptr<dae::GameObject>& bullet)
{
	m_pBullets.emplace_back(bullet);
	auto scene = dae::SceneManager::GetInstance().GetActiveScene();
	scene->Add(bullet);
}

void BulletManager::RemoveBullet(const std::shared_ptr<dae::GameObject>& bullet)
{
	if (m_pBullets.empty())
		return;

	auto scene = dae::SceneManager::GetInstance().GetActiveScene();
	scene->Remove(bullet);

	m_pBullets.erase(std::remove(m_pBullets.begin(), m_pBullets.end(), bullet));
}

void BulletManager::ClearBullets()
{
	auto scene = dae::SceneManager::GetInstance().GetActiveScene();
	for (const auto& bullet : m_pBullets)
	{
		
		scene->Remove(bullet);
	}
	m_pBullets.clear();
}

void BulletManager::Update()
{
	for (size_t i = 0; i < m_pBullets.size(); ++i)
	{
		m_pBullets[i]->Update();
	}
}

void BulletManager::FixedUpdate()
{
	for (size_t i = 0; i < m_pBullets.size(); ++i)
	{
		m_pBullets[i]->FixedUpdate();
	}
}
