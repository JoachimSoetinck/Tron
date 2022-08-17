#pragma once
#include "BaseComponent.h"

class BulletManager : public dae::BaseComponent
{
public:
	BulletManager(dae::GameObject* object) :BaseComponent(object) {}
	~BulletManager() override = default;

	BulletManager(const BulletManager& other) = delete;
	BulletManager(BulletManager&& other) noexcept = delete;
	BulletManager& operator=(const BulletManager& other) = delete;
	BulletManager& operator=(BulletManager&& other) noexcept = delete;

	void AddBullet(const std::shared_ptr<dae::GameObject>& bullet);
	void RemoveBullet(const std::shared_ptr<dae::GameObject>& bullet);
	void ClearBullets();

	void Update() override;
	void FixedUpdate() override;
	void Render() const override {}

	std::vector<std::shared_ptr<dae::GameObject>> m_pBullets{};
};



