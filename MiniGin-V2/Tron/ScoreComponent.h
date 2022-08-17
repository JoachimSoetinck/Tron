#pragma once
#include "BaseComponent.h"
#include "Observer.h"
#include "TankComponent.h"
#include "TextComponent.h"

class ScoreComponent : public dae::BaseComponent, public dae::Observer
{
public:
	ScoreComponent(dae::GameObject* object, dae::TankComponent* tank, dae::TextComponent* text);
	~ScoreComponent() = default;

	ScoreComponent(const ScoreComponent& other) = delete;
	ScoreComponent(ScoreComponent&& other) noexcept = delete;
	ScoreComponent& operator=(const ScoreComponent& other) = delete;
	ScoreComponent& operator=(ScoreComponent&& other) noexcept = delete;

	void OnNotify(Event event) override;


	void Update() override;
	void Render() const override;
	void FixedUpdate() override {};
	void SetScore();

private:
	dae::TextComponent* m_pTextComponent{};
	dae::TankComponent* m_pTank;
	SDL_Color m_color = SDL_Color{ 255,255,0 };

};

