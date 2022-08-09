#include "TronGame.h"

#include "CustomCommands.h"
#include "GameObject.h"
#include "InputManager.h"

#include "ResourceManager.h"
#include "RigidBody.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Sprite.h"
#include "SpriteComponent.h"
#include "TextComponent.h"
#include "CustomCommands.cpp"


void TronGame::LoadGame() const
{
	
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());


	const auto tank1{ dae::InputManager::GetInstance().AddPlayer(true) };


	// -- Attack --
	//dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonA, std::make_shared<FireCommand>(), tank1, dae::InputManager::EInputState::Down);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_E, std::make_shared<FireCommand>(), tank1, dae::InputManager::EInputState::Down);



	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 } ;
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 50,50,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));

	// -- MoveLeft --
	
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), glm::vec2{ -1,0}), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), glm::vec2{ 1,0 }), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), glm::vec2{ 0,-1 }), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), glm::vec2{ 0,1 }), tank1, dae::InputManager::EInputState::Pressed);


	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene.Add(Tank);

	
}
