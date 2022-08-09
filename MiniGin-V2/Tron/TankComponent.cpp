#include "TankComponent.h"

#include "GameObject.h"
#include "SpriteComponent.h"

void dae::TankComponent::SetState(TankState state)
{
	m_CurrentState = state;
	const auto spriteComp = GetGameObject()->GetComponent<SpriteComponent>();

	switch (m_CurrentState)
	{
	case TankState::idle:
	{
		m_direction = { 0,0 };
		break;
	}

	case TankState::Left:
	{
		m_direction = { -1,0 };
		spriteComp->SetRotation(270);
		break;
	}

	case TankState::Right:
	{
		m_direction = { 1,0 };
		spriteComp->SetRotation(90);
		break;
	}

	case TankState::Up:
	{
		m_direction = { 0,-1 };
		spriteComp->SetRotation(0);
		break;
	}

	case TankState::Down:
	{
		m_direction = { 0,1 };
		spriteComp->SetRotation(180);
		break;
	}
	default:
		break;
	}
}

dae::TankComponent::TankComponent(GameObject* gameObject) :
	BaseComponent(gameObject)
	, m_CurrentState{ TankState::idle }
	, m_RigidBody{ GetGameObject()->GetComponent<RigidBody>() }
{
}

void dae::TankComponent::Update()
{
}

void dae::TankComponent::Render() const
{
}

void dae::TankComponent::FixedUpdate()
{
	if (m_RigidBody)
	{
		if (m_direction != glm::ivec2{ 0,0 })
			m_RigidBody->Move(m_direction);
	}
}

void dae::TankComponent::Attack() const
{
}

void dae::TankComponent::Rotate()
{
}
