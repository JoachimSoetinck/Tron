#include "TankComponent.h"

#include "BulletComponent.h"
#include "BulletManager.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "SpriteComponent.h"
#include "Timer.h"
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
		//m_lookDirection = { -1,0 };

		spriteComp->SetRotation(270);
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h / 2;

		break;
	}

	case TankState::Right:
	{
		m_direction = { 1,0 };
		//m_lookDirection = { 1,0 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h / 2;
		spriteComp->SetRotation(90);
		break;
	}

	case TankState::Up:
	{
		m_direction = { 0,-1 };
		//m_lookDirection = { 0,-1 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w / 2;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y;
		spriteComp->SetRotation(0);
		break;
	}

	case TankState::Down:
	{
		m_direction = { 0,1 };
		//m_lookDirection = { 0,-1 };
		m_lookPoint.x = GetGameObject()->GetLocalPosition().x + spriteComp->GetDestRect().w / 2;
		m_lookPoint.y = GetGameObject()->GetLocalPosition().y + spriteComp->GetDestRect().h;
		spriteComp->SetRotation(180);

		break;
	}
	case TankState::Attack:
	{
		Attack();
		m_direction = { 0,0 };
		SetState(TankState::idle);
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
	, m_pSprite{ GetGameObject()->GetComponent<SpriteComponent>() }
{
	m_center = { GetGameObject()->GetLocalPosition().x + GetGameObject()->GetComponent<SpriteComponent>()->GetDestRect().w / 2,
		GetGameObject()->GetLocalPosition().y + GetGameObject()->GetComponent<SpriteComponent>()->GetDestRect().h / 2 };
}

void dae::TankComponent::Update()
{

	if(m_lookDirection.x >= 1.0f || m_lookDirection.x <= -1.0f )
	{
		m_turnSpeedX *= -1;
	}

	if (m_lookDirection.y >= 1.0f || m_lookDirection.y <= -1.0f)
	{
		m_turnSpeedY *= -1;
	}


	m_lookDirection.x -= m_turnSpeedX * dae::Time::GetInstance().GetDeltaTime();
	m_lookDirection.y += m_turnSpeedY * dae::Time::GetInstance().GetDeltaTime();

}

void dae::TankComponent::Render() const
{
	dae::Renderer::GetInstance().RenderPoint(m_lookPoint);


	dae::Renderer::GetInstance().DrawLine(m_center.x, m_center.y, m_center.x + m_lookDirection.x * 10, m_center.y + m_lookDirection.y * 10);
}

void dae::TankComponent::FixedUpdate()
{
	m_center = { GetGameObject()->GetLocalPosition().x + GetGameObject()->GetComponent<SpriteComponent>()->GetDestRect().w / 2,
		GetGameObject()->GetLocalPosition().y + GetGameObject()->GetComponent<SpriteComponent>()->GetDestRect().h / 2 };

	auto objects = dae::SceneManager::GetInstance().GetScene(dae::SceneManager::GetInstance().GetActiveSceneNr())->GetObjects();

	for (auto object : objects)
	{
		if (object->GetComponent<WallComponent>())
		{
			bool isColliding = IsPointInRect(m_lookPoint, object->GetComponent<WallComponent>()->GetWallInfo());

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
	const auto bullet{ std::make_shared<dae::GameObject>() };
	bullet->AddComponent(new SpriteComponent(bullet.get(), Sprite("TronSprite.png", 1, 1, { 192,0,10,10 }), { 0,0,10,10 }));
	bullet->AddComponent(new RigidBody(bullet.get()));
	bullet->AddComponent(new CollisionComponent(bullet.get(), 10));
	bullet->AddComponent(new BulletComponent(bullet.get(), m_lookDirection));

	const auto pos{ GetGameObject()->GetLocalPosition() };
	bullet->SetPosition(m_center.x , m_center.y - bullet->GetComponent<SpriteComponent>()->GetDestRect().h/2);
	GetGameObject()->GetComponent<BulletManager>()->AddBullet(bullet);

}

void dae::TankComponent::Rotate()
{

	


}

bool dae::TankComponent::IsPointInRect(const glm::vec2& point, SDL_Rect otherRect)
{
	const auto objPos = GetGameObject()->GetLocalPosition();
	SDL_Rect rect{ static_cast<int>(otherRect.x), static_cast<int>(otherRect.y), otherRect.w,otherRect.h };
	if (point.x >= rect.x && point.x <= rect.x + rect.w && point.y >= rect.y && point.y <= rect.y + rect.h)
		return true;
	return false;
}


