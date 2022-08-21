#include "ControllerComponent.h"

#include "SceneManager.h"

ControllerComponent::ControllerComponent(dae::GameObject* object, dae::TankComponent* tank) :BaseComponent(object),
m_pTank{ tank }
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
		int currentScene = dae::SceneManager::GetInstance().GetActiveSceneNr();
		++currentScene;
		if(currentScene > 10)
		{
			dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());
		}
		dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(currentScene).get());
		
	}
}

void ControllerComponent::FixedUpdate()
{
}