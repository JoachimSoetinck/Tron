#include "MiniginPCH.h"
#include "InputManager.h"

#include "Scene.h"
#include "SceneManager.h"
#include "backends/imgui_impl_sdl.h"


dae::InputManager::InputManager()
{
	
}

dae::InputManager::~InputManager()
{
	for (auto element : m_KeyBoardCommands)
	{
		delete element;
		element = nullptr;
	}

	for (auto element : m_ConsoleCommands)
	{
		delete element;
		element = nullptr;
	}

}

bool dae::InputManager::ProcessInput()
{

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}

		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_KEYDOWN) {

		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {

		}
		if (e.type == SDL_KEYUP) {
			{
				if (e.key.keysym.sym == SDLK_1) {
					//SceneManager::GetInstance().SetActiveScene(SceneManager::GetInstance().GetScene(1).get());
				}

				if (e.key.keysym.sym == SDLK_2) {
					//SceneManager::GetInstance().SetActiveScene(SceneManager::GetInstance().GetScene(5).get());
				}


			}
		}
	}

	Update();

	for (const auto& controller : m_ConsoleCommands)
	{
		switch (controller->state)
		{
		case EInputState::Down:
			if (IsDownThisFrame(controller->controllerButton, controller->playerNr))
				controller->command->Execute();
			break;
		case EInputState::Pressed:
			if (IsPressed(controller->controllerButton, controller->playerNr))
				controller->command->Execute();
			break;
		case EInputState::Up:
			if (IsUpThisFrame(controller->controllerButton, controller->playerNr))
				controller->command->Execute();
			break;
		}
	}

	for (const auto& keyboard : m_KeyBoardCommands)
	{
		switch (keyboard->state)
		{
		case EInputState::Down:
			if (IsDownThisFrame(keyboard->button, keyboard->playerNr))
				keyboard->command->Execute();
			break;
		case EInputState::Pressed:
			if (IsPressed(keyboard->button, keyboard->playerNr))
				keyboard->command->Execute();
			break;
		case EInputState::Up:
			if (IsUpThisFrame(keyboard->button, keyboard->playerNr))
				keyboard->command->Execute();
			break;
		}
	}


	return true;
}



void dae::InputManager::Update()
{

	for (const auto& controller : m_pControllers)
	{
		controller->Update();
	}
	for (const auto& keyboard : m_pKeyBoards)
	{
		keyboard->Update();
	}
	

}

int dae::InputManager::AddPlayer(bool IsKeyBoard)
{
	if (IsKeyBoard)
	{
		int index = static_cast<int>(m_pKeyBoards.size());
		m_pKeyBoards.push_back(std::make_unique<KeyBoard>(index));
		return index;
	}
	int index = static_cast<int>(m_pControllers.size());
	m_pControllers.push_back(std::make_unique<XboxController>(index));
	return index;
}


bool dae::InputManager::IsPressed(XboxController::Button button, int  playerNr) const
{
	return m_pControllers[playerNr]->IsPressed(button);
}

bool dae::InputManager::IsPressed(SDL_Scancode scancode, int playerNr) const
{
	return m_pKeyBoards[playerNr]->IsPressed(scancode);
}

bool dae::InputManager::IsDownThisFrame(XboxController::Button button, int playerNr) const
{
	return m_pControllers[playerNr]->IsDown(button);
}

bool dae::InputManager::IsDownThisFrame(SDL_Scancode scancode, int playerNr) const
{
	return m_pKeyBoards[playerNr]->IsDown(scancode);
}

bool dae::InputManager::IsUpThisFrame(XboxController::Button button, int playerNr) const
{
	return m_pControllers[playerNr]->IsUp(button);
}

bool dae::InputManager::IsUpThisFrame(SDL_Scancode scancode, int playerNr) const
{
	return m_pKeyBoards[playerNr]->IsUp(scancode);
}

void dae::InputManager::AddCommand(XboxController::Button button, std::shared_ptr<Command> command, int playerNr, EInputState state)
{
	if (playerNr > m_pControllers.size())
	{
		std::cout << "No Player" << std::endl;
		return;
	}
	ControllerAction* action  = new ControllerAction();
	action->command = command;
	action->controllerButton = button;
	action->state = state;
	action->playerNr = playerNr;
	m_ConsoleCommands.emplace_back(action);

}

void dae::InputManager::AddCommand(SDL_Scancode keyBoardKey, std::shared_ptr<Command> command, int playerNr, EInputState state)
{

	if (playerNr > m_pKeyBoards.size())
	{
		std::cout << "No Playerr" << std::endl;
		return;
	}
	KeyboardAction* action = new KeyboardAction();
	action->button = keyBoardKey;
	action->command = command;
	action->state = state;
	action->playerNr = playerNr;

	m_KeyBoardCommands.emplace_back(action);
}

void dae::InputManager::RemoveCommand(XboxController::Button , std::shared_ptr<Command> , int, EInputState )
{
}

void dae::InputManager::RemoveCommand(SDL_Scancode , std::shared_ptr<Command> , int, EInputState )
{
}


