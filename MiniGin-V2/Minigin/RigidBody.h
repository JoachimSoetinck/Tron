#pragma once
#include "BaseComponent.h"

namespace dae
{

	class RigidBody :
		public dae::BaseComponent
	{
	public:
		RigidBody(dae::GameObject* object, const glm::vec2& speed = {50,50});
		~RigidBody() override = default;

		RigidBody(const RigidBody& other) = delete;
		RigidBody(RigidBody&& other) noexcept = delete;
		RigidBody& operator=(const RigidBody& other) = delete;
		RigidBody& operator=(RigidBody&& other) noexcept = delete;

		void Update() override {};
		void FixedUpdate() override {};
		void Render() const override {};
		void Move(const glm::vec2& moveVec);

		glm::vec2 GetMovementSpeed() const { return m_MovementSpeed; }
		glm::vec2 GetVelocity()const { return m_Velocity; }

	private:

		glm::vec2 m_MovementSpeed{ 200,200 };
		glm::vec2 m_Velocity{};
	};
}

