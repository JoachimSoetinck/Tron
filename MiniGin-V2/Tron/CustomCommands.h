#pragma once
#pragma once
#include "Command.h"
#include <memory>



#include "SpriteComponent.h"
#include <BaseComponent.h>
#include <RigidBody.h>

#include "TankComponent.h"

class MoveCommand final : public Command
{
public:
	MoveCommand(dae::GameObject* gameObject, dae::TankComponent::TankState state) :Command(gameObject), m_state{ state } {}
	~MoveCommand() override = default;

	MoveCommand(const MoveCommand& other) = delete;
	MoveCommand(MoveCommand&& other) noexcept = delete;
	MoveCommand& operator=(const MoveCommand& other) = delete;
	MoveCommand& operator=(MoveCommand&& other) noexcept = delete;

	void Execute() override
	{

		GetGameObject()->GetComponent<dae::TankComponent>()->SetState(m_state);


	}
private:
	dae::TankComponent::TankState m_state;
};





