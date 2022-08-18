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

class Test final : public Command
{
public:
	Test(dae::GameObject* gameObject) :Command(gameObject) {}
	~Test() override = default;

	Test(const Test& other) = delete;
	Test(Test&& other) noexcept = delete;
	Test& operator=(const Test& other) = delete;
	Test& operator=(Test&& other) noexcept = delete;

	void Execute() override
	{
		std::cout << "Test";
	}
private:
	dae::TankComponent::TankState m_state;
};

class AttackCommand final : public Command
{
public:
	AttackCommand(dae::GameObject* gameObject) :Command(gameObject) {}
	~AttackCommand() override = default;

	AttackCommand(const AttackCommand& other) = delete;
	AttackCommand(AttackCommand&& other) noexcept = delete;
	AttackCommand& operator=(const AttackCommand& other) = delete;
	AttackCommand& operator=(AttackCommand&& other) noexcept = delete;

	void Execute() override
	{
		GetGameObject()->GetComponent<dae::TankComponent>()->SetState(dae::TankComponent::TankState::Attack);
	}
private:

};

class RotateCommand final : public Command
{
public:
	RotateCommand(dae::GameObject* gameObject, bool canRotate, bool rotationClockWise) :Command(gameObject), m_canRotate{canRotate}, m_RotateClockwise{ rotationClockWise } {}
	~RotateCommand() override = default;

	RotateCommand(const RotateCommand& other) = delete;
	RotateCommand(RotateCommand&& other) noexcept = delete;
	RotateCommand& operator=(const RotateCommand& other) = delete;
	RotateCommand& operator=(RotateCommand&& other) noexcept = delete;

	void Execute() override
	{
		GetGameObject()->GetComponent<dae::TankComponent>()->SetRotation(m_canRotate, m_RotateClockwise);
	}
private:
	bool m_canRotate{};
	bool m_RotateClockwise{};
	
};





