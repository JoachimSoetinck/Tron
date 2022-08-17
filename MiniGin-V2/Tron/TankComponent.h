#pragma once
#include "BaseComponent.h"
#include "RigidBody.h"
#include "SpriteComponent.h"
#include "Subject.h"


namespace dae
{
	class TankComponent final: public dae::BaseComponent, public Subject
	{
	public:
		enum class TankState
		{
			Left, Right, Up, Down, Attack, idle
		};

		
		
		TankComponent(GameObject* gameObject);
		~TankComponent() override = default;
		TankComponent(const TankComponent& other) = delete;
		TankComponent(TankComponent&& other) noexcept = delete;
		TankComponent& operator=(const TankComponent& other) = delete;
		TankComponent& operator=(TankComponent&& other) noexcept = delete;

		void Update() override;
		void Render() const override;
		void FixedUpdate() override;

		void SetState(TankState state);
		int GetLives() const { return m_nrOfLives; };
		void Rotate();


	private:
		TankState m_CurrentState;
		glm::ivec2 m_direction{ 0,0 };
		glm::vec2 m_lookDirection{ 1,0 };
		glm::ivec2 m_lookPoint{0,0};
		dae::RigidBody* m_RigidBody;

		int m_nrOfLives{ 3 };
		int m_score{ 0 };

		float m_TurretAngle{};
		float m_RotationSpeed{ 40 };

		float m_turnSpeedX{ 0.5f };
		float m_turnSpeedY{ 0.5f };

		SpriteComponent* m_pSprite{};

		void Attack();
		void LoseLive();
		
		float m_attackCoolDown{2.0f};
		float elapsedSec{ 0.0f };
		bool m_hasAttacked{false};

		bool IsPointInRect(const glm::vec2& point, SDL_Rect rect);

		glm::ivec2 m_center{};
	};
}


