#include "ControllerComponent.h"

#include "SceneManager.h"

ControllerComponent::ControllerComponent(dae::GameObject* object, dae::TankComponent* tank, dae::Scene* nextScene) :BaseComponent(object),
m_pTank{ tank },
m_pScene{ nextScene }
{

}

void ControllerComponent::Render() const
{
}

void ControllerComponent::Update()
{
	if (m_pTank->GetLives() <= 0)
	{
		dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());
	}

	if (m_pTank->GetScore() >= 300)
	{
		dae::SceneManager::GetInstance().SetActiveScene(m_pScene);
	}
}

void ControllerComponent::FixedUpdate()
{
}
