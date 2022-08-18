#include "BulletComponent.h"

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Renderer.h"
#include "RigidBody.h"
#include "Scene.h"
#include "SceneManager.h"
#include "TankComponent.h"
#include "WallComponent.h"

BulletComponent::BulletComponent(dae::GameObject* object, const glm::vec2 direction, dae::GameObject* parent) :
	BaseComponent(object),
	m_NrOfBounces{ 0 },
	m_maxNrOfBounces{ 5 },
	m_direction{ direction },
	m_pRigidBody{ GetGameObject()->GetComponent<dae::RigidBody>() }
{
	m_pGameObject->SetParent(parent, true);
}

void BulletComponent::Render() const
{


}

void BulletComponent::Update()
{
	if (m_pRigidBody != nullptr)
	{
		m_pRigidBody->Move(m_direction);
	}
}

void BulletComponent::FixedUpdate()
{
	//auto objects = dae::SceneManager::GetInstance().GetScene(dae::SceneManager::GetInstance().GetActiveSceneNr())->GetObjects();
	auto objects = dae::SceneManager::GetInstance().GetActiveScene()->GetObjects();

	for (auto object : objects)
	{
		if (object->GetComponent<WallComponent>() )
		{
			//bool isColliding = IsPointInRect(m_lookPoint, object->GetComponent<WallComponent>()->GetWallInfo());

			if (m_pGameObject->GetComponent<CollisionComponent>()->IsOverlapping(object->GetComponent<CollisionComponent>()))
			{
				m_isDead = true;
				

			}

		}

		if (object->GetComponent<dae::TankComponent>() )
		{
			//bool isColliding = IsPointInRect(m_lookPoint, object->GetComponent<WallComponent>()->GetWallInfo());

			if (m_pGameObject->GetComponent<CollisionComponent>()->IsOverlapping(object->GetComponent<CollisionComponent>()))
			{
				m_isDead = true;

				if(m_pGameObject->GetParent()->GetComponent<dae::TankComponent>())
				{
					m_pGameObject->GetParent()->GetComponent<dae::TankComponent>()->GivePoints(100);
					m_pGameObject->GetParent()->GetComponent<dae::TankComponent>()->NotifyAllObservers(Event::GivePoints);
					object->GetComponent<dae::TankComponent>()->LoseLive();

				}


			}

		}

	}

}
