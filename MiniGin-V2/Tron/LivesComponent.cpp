#include "LivesComponent.h"

#include "TextComponent.h"


dae::LivesComponent::LivesComponent(dae::GameObject* object, TankComponent* tank, TextComponent* text) :BaseComponent(object),
m_pTank{ tank },
m_pTextComponent{ text }
{


	SetLives();
}

void dae::LivesComponent::OnNotify( Event action)
{
	switch (action)
	{
	case Event::Died:
		SetLives();
		break;
	default:;
	}

}

void dae::LivesComponent::Update()
{
	if (m_pTextComponent != nullptr)
	{
		m_pTextComponent->Update();
	}


}

void dae::LivesComponent::Render() const
{
	m_pTextComponent->Render();
}

void dae::LivesComponent::SetLives()
{
	if (m_pTextComponent != nullptr)
	{
		const int lives = m_pTank->GetLives();
		// text
		std::stringstream ssText;
		ssText << "Lives: " << lives;
		m_pTextComponent->SetText(ssText.str());

	}
}
