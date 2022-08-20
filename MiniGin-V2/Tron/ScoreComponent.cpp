#include "ScoreComponent.h"

ScoreComponent::ScoreComponent(dae::GameObject* object, dae::TankComponent* tank, dae::TextComponent* text) :BaseComponent(object),
m_pTank{ tank },
m_pTextComponent{ text }
{


	SetScore();

}

void ScoreComponent::OnNotify(Event event)
{
	switch (event)
	{
	case Event::GivePoints:
	{
		SetScore();
		break;
	}

	default:;
	}
}

void ScoreComponent::Update()
{
	SetScore();
}

void ScoreComponent::Render() const
{
}

void ScoreComponent::SetScore()
{
	if (m_pTextComponent != nullptr)
	{
		const int lives = m_pTank->GetScore();
		// text
		std::stringstream ssText;
		ssText << "Score: " << lives;
		m_pTextComponent->SetText(ssText.str());

	}
}


