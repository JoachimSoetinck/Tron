#include "BulletComponent.h"

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Renderer.h"
#include "RigidBody.h"
#include "Scene.h"
#include "SceneManager.h"
#include "WallComponent.h"

BulletComponent::BulletComponent(dae::GameObject* object, const glm::vec2 direction) :
	BaseComponent(object),
	m_NrOfBounces{ 0 },
	m_maxNrOfBounces{ 5 },
	m_direction{ direction },
	m_pRigidBody{ GetGameObject()->GetComponent<dae::RigidBody>() }
{

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
	}

}
