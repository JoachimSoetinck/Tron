#pragma once
#include "BaseComponent.h"
#include "RigidBody.h"

namespace dae
{
	class TankComponent final: public dae::BaseComponent
	{
	public:
		enum class TankState
		{
			Left, Right, Up, Down, Attack, idle
		};

		
		void SetState(TankState state);

		TankComponent(GameObject* gameObject);
		~TankComponent() override = default;
		TankComponent(const TankComponent& other) = delete;
		TankComponent(TankComponent&& other) noexcept = delete;
		TankComponent& operator=(const TankComponent& other) = delete;
		TankComponent& operator=(TankComponent&& other) noexcept = delete;

		void Update() override;
		void Render() const override;
		void FixedUpdate() override;

		

	private:
		TankState m_CurrentState;
		glm::ivec2 m_direction{ 0,0 };
		glm::vec2 m_lookPoint{0,0};
		dae::RigidBody* m_RigidBody;
		

		void Attack() const;
		void Rotate();

		bool IsPointInRect(const glm::vec2& point, SDL_Rect rect);
	};
}


