#include "BulletComponent.h"

#include "GameObject.h"
#include "Renderer.h"
#include "RigidBody.h"

BulletComponent::BulletComponent(dae::GameObject* object, const glm::vec2 direction):
BaseComponent(object),
m_NrOfBounces{0},
m_maxNrOfBounces{5},
m_direction{direction},
m_pRigidBody{ GetGameObject()->GetComponent<dae::RigidBody>() }
{

}

void BulletComponent::Render() const
{


}

void BulletComponent::Update()
{
	if(m_pRigidBody != nullptr)
	{
		m_pRigidBody->Move(m_direction);
	}
}

void BulletComponent::FixedUpdate()
{

}
