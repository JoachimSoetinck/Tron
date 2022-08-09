#pragma once
#include "BaseComponent.h"

class BulletComponent final: public dae::BaseComponent
{
public:
	BulletComponent(dae::GameObject* object, const glm::vec2 direction);
	~BulletComponent() override = default;
	BulletComponent(const BulletComponent& other) = delete;
	BulletComponent(BulletComponent&& other) noexcept = delete;
	BulletComponent& operator=(const BulletComponent& other) = delete;
	BulletComponent& operator=(BulletComponent&& other) noexcept = delete;

	void Render() const override;
	void Update() override;
	void FixedUpdate() override;

private:
	glm::vec2 m_direction;
	int m_NrOfBounces{ 0 };
	const int m_maxNrOfBounces;
};

