#pragma once
#include <functional>

#include "BaseComponent.h"

namespace dae
{
	class TextComponent;

	class ButtonComponent final : public dae::BaseComponent
	{
	public:
		ButtonComponent(dae::GameObject* object, TextComponent* pTextComponent );
		~ButtonComponent() = default;
		ButtonComponent(const ButtonComponent& other) = delete;
		ButtonComponent(ButtonComponent&& other) noexcept = delete;
		ButtonComponent& operator=(const ButtonComponent& other) = delete;
		ButtonComponent& operator=(ButtonComponent&& other) noexcept = delete;
		void Render() const override;
		void Update() override;
		void FixedUpdate() override;

		void SetFunction(std::function<void()> action) { m_Action = action; };
		

	private:
		TextComponent* m_pText{};
		std::function<void()> m_Action{};

		void PrintButtonText();
		bool m_isPressed = false;
		SDL_Rect m_SrcRect{};
		SDL_Color m_OriginalColor{};
	};
}


