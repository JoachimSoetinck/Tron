#pragma once
#include "GameObject.h"
#include "Scene.h"
#include "TankComponent.h"

class ControllerComponent final : public dae::BaseComponent
{
public:
	ControllerComponent(dae::GameObject* object,dae::TankComponent* tank, dae::Scene* nextScene);
	~ControllerComponent() override = default;
	ControllerComponent(const ControllerComponent& other) = delete;
	ControllerComponent(ControllerComponent&& other) noexcept = delete;
	ControllerComponent& operator=(const ControllerComponent& other) = delete;
	ControllerComponent& operator=(ControllerComponent&& other) noexcept = delete;

	void Render() const override;
	void Update() override;
	void FixedUpdate() override;


private:
	dae::TankComponent* m_pTank;
	dae::Scene* m_pScene;

};


