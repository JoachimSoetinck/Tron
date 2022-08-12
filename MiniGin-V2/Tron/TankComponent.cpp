#include "TankComponent.h"

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SpriteComponent.h"
#include "WallComponent.h"

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
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h / 2;
		
		break;
	}

	case TankState::Right:
	{
		m_direction = { 1,0 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w ;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h / 2;
		spriteComp->SetRotation(90);
		break;
	}

	case TankState::Up:
	{
		m_direction = { 0,-1 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w /2 ;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y;
		spriteComp->SetRotation(0);
		break;
	}

	case TankState::Down:
	{
		m_direction = { 0,1 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w / 2;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h;
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
	dae::Renderer::GetInstance().RenderPoint(m_lookPoint);
}

void dae::TankComponent::FixedUpdate()
{


	auto objects = dae::SceneManager::GetInstance().GetScene(dae::SceneManager::GetInstance().GetActiveSceneNr())->GetObjects();

	for (auto object : objects)
	{
		if (object->GetComponent<WallComponent>())
		{
			bool isColliding = IsPointInRect(m_lookPoint,object->GetComponent<WallComponent>()->GetWallInfo());

		
			if (isColliding)
			{
				SetState(TankState::idle);
			}
		}
	}

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

bool dae::TankComponent::IsPointInRect(const glm::vec2& point, SDL_Rect otherRect)
{
	const auto objPos = GetGameObject()->GetLocalPosition();
	SDL_Rect rect{ static_cast<int>(otherRect.x ), static_cast<int>(otherRect.y), otherRect.w,otherRect.h };
	if (point.x >= rect.x && point.x <= rect.x + rect.w && point.y >= rect.y && point.y <= rect.y + rect.h)
		return true;
	return false;
}
