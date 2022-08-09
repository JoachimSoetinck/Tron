#include "CustomCommands.h"

#include "MovementComponent.h"
#include "SpriteComponent.h"
#include <BaseComponent.h>
#include <RigidBody.h>

class MoveCommand final : public Command
{
public:
	MoveCommand(dae::GameObject* gameObject, const glm::vec2& moveVec) :Command(gameObject), m_MoveVec(moveVec) {}
	~MoveCommand() override = default;

	MoveCommand(const MoveCommand& other) = delete;
	MoveCommand(MoveCommand&& other) noexcept = delete;
	MoveCommand& operator=(const MoveCommand& other) = delete;
	MoveCommand& operator=(MoveCommand&& other) noexcept = delete;

	void Execute() override
	{
		
		GetGameObject()->GetComponent<dae::RigidBody>()->Move(m_MoveVec);
		if (m_MoveVec.x == 0)
		{
			if (m_MoveVec.y > 0)
				GetGameObject()->GetComponent<SpriteComponent>()->SetRotation(180);
			else
				GetGameObject()->GetComponent<SpriteComponent>()->SetRotation(0);
		}
		else
		{
			if (m_MoveVec.x > 0)
				GetGameObject()->GetComponent<SpriteComponent>()->SetRotation(90);
			else
				GetGameObject()->GetComponent<SpriteComponent>()->SetRotation(270);
		}

	}
private:
	glm::vec2 m_MoveVec;
};
