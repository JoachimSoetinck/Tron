#pragma once
#pragma once
#include "BaseComponent.h"
#include "TankComponent.h"

namespace dae
{
	class TextComponent;

	class LivesComponent : public BaseComponent, public Observer
	{
	public:
		LivesComponent(dae::GameObject* object, TankComponent* tank, TextComponent* text);
		~LivesComponent() = default;

		LivesComponent(const LivesComponent& other) = delete;
		LivesComponent(LivesComponent&& other) noexcept = delete;
		LivesComponent& operator=(const LivesComponent& other) = delete;
		LivesComponent& operator=(LivesComponent&& other) noexcept = delete;

		void OnNotify( Event event) override;


		void Update() override;
		void Render() const override;
		void FixedUpdate() override{};
		void SetLives();

	private:

		TextComponent* m_pTextComponent{};
		TankComponent* m_pTank;
		SDL_Color m_color = SDL_Color{ 255,255,0 };

	};

}

