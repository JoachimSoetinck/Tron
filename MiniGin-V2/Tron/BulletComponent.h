#pragma once
#include "BaseComponent.h"

namespace dae
{
	class RigidBody;
}

class BulletComponent final: public dae::BaseComponent
{
public:
	BulletComponent(dae::GameObject* object, const glm::vec2 direction, dae::GameObject* parent);
	~BulletComponent() override = default;
	BulletComponent(const BulletComponent& other) = delete;
	BulletComponent(BulletComponent&& other) noexcept = delete;
	BulletComponent& operator=(const BulletComponent& other) = delete;
	BulletComponent& operator=(BulletComponent&& other) noexcept = delete;

	void Render() const override;
	void Update() override;
	void FixedUpdate() override;
	bool IsDead()const
	{
		return m_isDead;
	};

private:
	glm::vec2 m_direction{1,0};
	int m_NrOfBounces{ 0 };
	const int m_maxNrOfBounces;

	bool m_isDead = false;

	dae::RigidBody* m_pRigidBody{};
};

