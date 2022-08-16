#include "MiniginPCH.h"
#include "ButtonComponent.h"

#include "InputManager.h"
#include "Renderer.h"
#include "TextComponent.h"

dae::ButtonComponent::ButtonComponent(dae::GameObject* object, TextComponent* pTextComponent) :
	BaseComponent(object),
	m_pText{ pTextComponent },
	m_OriginalColor{ m_pText->GetColor() }
{
	if (m_pText)
		m_SrcRect = { m_pText->GetPosition().x ,m_pText->GetPosition().y , m_pText->GetDimensions().x, m_pText->GetDimensions().y };

	SetFunction([]()
	{
			std::cout << "Hello\n";
	});
}

void dae::ButtonComponent::Render() const
{
	SDL_Rect Button = { m_pText->GetPosition().x ,m_pText->GetPosition().y , m_pText->GetDimensions().x, m_pText->GetDimensions().y };

	Renderer::GetInstance().DrawRectangle(Button);
}

void dae::ButtonComponent::Update()
{
	if (m_pText != nullptr)
	{
		auto mousePos = dae::InputManager::GetInstance().GetMousePos();
		if (mousePos.x >= m_SrcRect.x && mousePos.y >= m_SrcRect.y && mousePos.x <= m_SrcRect.x + m_SrcRect.w && mousePos.y <= m_SrcRect.y + m_SrcRect.h)
		{
			m_pText->SetColor(SDL_Color{ 255,0,0 });

			if(InputManager::GetInstance().IsMousePress() && m_isPressed ==false)
			{
				m_isPressed = true;
				m_Action();
				
			}
		}
		else
		{
			m_pText->SetColor(m_OriginalColor);
		}
	}
}

void dae::ButtonComponent::FixedUpdate()
{
}

void dae::ButtonComponent::PrintButtonText()
{
	std::cout << "Hello\n";
}
