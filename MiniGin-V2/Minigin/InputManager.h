#pragma once
#include <XInput.h>
#include "Singleton.h"
#include <map>
#include <memory>

#include "Command.h"
#include "Keyboard.h"
#include "XboxController.h"


namespace dae
{

	class InputManager final : public Singleton<InputManager>
	{

	public:

		//Mouse 
		enum class EMouseButton
		{
			Left, Middle, Right
		};

		//Type Press
		enum class EInputState
		{
			Down,
			Pressed,
			Up
		};


		struct PlayerAction
		{
			EInputState state{};
			std::shared_ptr<Command> command{};
			int playerNr{};
			virtual ~PlayerAction() = default;
		};

		struct ControllerAction final : public PlayerAction
		{
			ControllerAction() = default;
			~ControllerAction() override = default;
			XboxController::Button controllerButton{};
		};

		struct KeyboardAction final : public PlayerAction
		{
			KeyboardAction() = default;
			~KeyboardAction() override = default;

			SDL_Scancode button{};
			bool isPrevFrameDown{ false };
		};

		InputManager();
		~InputManager();
		bool ProcessInput();
		void Update();


		int AddPlayer(bool IsKeyBoard = false);
		

		bool IsPressed(XboxController::Button button, int playerNr) const;
		bool IsPressed(SDL_Scancode scancode, int playerNr) const;

		bool IsDownThisFrame(XboxController::Button button, int playerNr) const;
		bool IsDownThisFrame(SDL_Scancode scancode, int playerNr) const;

		bool IsUpThisFrame(XboxController::Button button, int playerNr) const;
		bool IsUpThisFrame(SDL_Scancode scancode, int playerNr) const;


		void AddCommand(XboxController::Button button, std::shared_ptr<Command> command, int playerNr, EInputState state = EInputState::Down);
		void AddCommand(SDL_Scancode keyBoardKey, std::shared_ptr<Command> command, int playerNr, EInputState state = EInputState::Down);

		void RemoveCommand(XboxController::Button button, std::shared_ptr<Command> command, int playerNr, EInputState state = EInputState::Down);
		void RemoveCommand(SDL_Scancode keyBoardKey, std::shared_ptr<Command> command, int playerNr, EInputState state = EInputState::Down);

		glm::ivec2 GetMousePos()const { return m_MousePos; };

		bool IsMousePress() const { return m_isPressed; };
	private:
		
		
		const Uint8* m_pCurrentState{};
		Uint8* m_pPreviousState{};

		std::vector<KeyboardAction*> m_KeyBoardCommands{};
		std::vector<ControllerAction*> m_ConsoleCommands{};

		std::vector<std::unique_ptr<XboxController>> m_pControllers{};
		std::vector<std::unique_ptr<KeyBoard>> m_pKeyBoards{};

		SDL_Event m_Event{};

		glm::ivec2 m_MousePos{};

		bool m_isPressed{ false };



	};

}
