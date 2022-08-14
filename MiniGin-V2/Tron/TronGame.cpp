#include "TronGame.h"

#include "CollisionComponent.h"
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
#include "CustomCommands.h"
#include "TankComponent.h"
#include "WallComponent.h"


void TronGame::LoadGame() const
{
	
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());


	const auto tank1{ dae::InputManager::GetInstance().AddPlayer() };


	// -- Attack --
	//dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonA, std::make_shared<FireCommand>(), tank1, dae::InputManager::EInputState::Down);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_E, std::make_shared<FireCommand>(), tank1, dae::InputManager::EInputState::Down);



	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 } ;
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->SetPosition(50, 50);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));
	Tank2->SetPosition(300, 300);
	
	
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);


	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);


	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);

	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	//dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);


	//auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene.Add(Tank);
	scene.Add(Tank2);



	const auto wall{ std::make_shared<dae::GameObject>() };
	wall->AddComponent(new WallComponent{ wall.get(), {0, 0, 480, 16} });
	scene.Add(wall);

	
}
