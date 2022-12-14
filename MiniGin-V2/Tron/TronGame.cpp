#include "TronGame.h"

#include "BulletManager.h"
#include "ButtonComponent.h"
#include "CollisionComponent.h"
#include "ControllerComponent.h"
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
#include "LevelParser.h"
#include "LivesComponent.h"
#include "ScoreComponent.h"
#include "ServiceLocator.h"
#include "TankComponent.h"
#include "WallComponent.h"


void TronGame::HandleInputPlayer(const std::shared_ptr<dae::GameObject> Tank, const int tank1) const
{
	switch (tank1)
	{
	case 0:
	{
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonRightShoulder, std::make_shared<RotateCommand>(Tank.get(), true, true), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonRightShoulder, std::make_shared<RotateCommand>(Tank.get(), false, false), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonLeftShoulder, std::make_shared<RotateCommand>(Tank.get(), true, false), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonLeftShoulder, std::make_shared<RotateCommand>(Tank.get(), false, false), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonA, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);

		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_SPACE, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_E, std::make_shared<RotateCommand>(Tank.get(), true, false), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_R, std::make_shared<RotateCommand>(Tank.get(), true, true), tank1, dae::InputManager::EInputState::Down);
		break;
	}
	case 1:
	{
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonRightShoulder, std::make_shared<RotateCommand>(Tank.get(), true, true), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonRightShoulder, std::make_shared<RotateCommand>(Tank.get(), false, false), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonLeftShoulder, std::make_shared<RotateCommand>(Tank.get(), true, false), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonLeftShoulder, std::make_shared<RotateCommand>(Tank.get(), false, false), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonA, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);

		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_LEFT, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_RIGHT, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_UP, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_DOWN, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_P, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_LEFT, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_RIGHT, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_UP, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_DOWN, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_I, std::make_shared<RotateCommand>(Tank.get(), true, false), tank1, dae::InputManager::EInputState::Down);
		dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_O, std::make_shared<RotateCommand>(Tank.get(), true, true), tank1, dae::InputManager::EInputState::Down);
		break;
	}
	default: break;
	}

}

void TronGame::CreateLivesText(dae::Scene& scene2, const std::shared_ptr<dae::GameObject> Tank, glm::vec3 pos) const
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);
	const auto lives{ std::make_shared<dae::GameObject>() };
	auto livesText = new dae::TextComponent(lives.get(), "Lives:", font);
	livesText->SetPosition(pos);
	lives->AddComponent(livesText);
	auto livesObserver = new dae::LivesComponent(lives.get(), Tank->GetComponent<dae::TankComponent>(), livesText);
	lives->AddComponent(livesObserver);
	scene2.Add(lives);
}

void TronGame::CreateScoreText(dae::Scene& scene2, std::shared_ptr<dae::GameObject> Tank, glm::vec3 pos) const
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);
	const auto score{ std::make_shared<dae::GameObject>() };
	auto scoreText = new dae::TextComponent(score.get(), "Lives:", font);
	scoreText->SetPosition(pos);
	score->AddComponent(scoreText);
	auto scoreObserver = new ScoreComponent(score.get(), Tank->GetComponent<dae::TankComponent>(), scoreText);
	score->AddComponent(scoreObserver);
	scene2.Add(score);
}

void TronGame::CreateLevel1(dae::Scene& scene2, bool isCoop, bool  isVersus) const
{

	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->AddComponent(new ControllerComponent(Tank.get(), Tank->GetComponent<dae::TankComponent>()));
	Tank->SetPosition(70, 100);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));
	Tank2->AddComponent(new BulletManager(Tank2.get()));
	Tank2->SetPosition(300, 305);


	HandleInputPlayer(Tank, 0);

	if (isCoop)
	{

		const auto Tank3{ std::make_shared<dae::GameObject>() };
		SDL_Rect src2{ 256,0,32,32 };
		Tank3->AddComponent(new SpriteComponent(Tank3.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
		Tank3->AddComponent(new dae::RigidBody(Tank3.get()));
		Tank3->AddComponent(new CollisionComponent(Tank3.get(), 25));
		Tank3->AddComponent(new dae::TankComponent(Tank3.get()));
		Tank3->AddComponent(new BulletManager(Tank3.get()));
		Tank3->SetPosition(300, 100);
		scene2.Add(Tank3);
		HandleInputPlayer(Tank3, 1);
	}

	else if (isVersus)
	{

		HandleInputPlayer(Tank2, 1);
	}


	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	CreateLivesText(scene2, Tank, { 0,0,0 });
	CreateLivesText(scene2, Tank2, { 400,0,0 });
	CreateScoreText(scene2, Tank, { 200,0,0 });

	if (isVersus)
	{
		CreateLivesText(scene2, Tank2, { 400,0,0 });
		CreateScoreText(scene2, Tank2, { 600,0,0 });
	}
	CreateScoreText(scene2, Tank2, { 600,0,0 });


	const auto button = std::make_shared<dae::GameObject>();
	auto textComponent = new dae::TextComponent(button.get(), "Skip", font);
	textComponent->SetPosition({ 300, 550,0 });
	button->AddComponent(textComponent);
	button->AddComponent(new dae::ButtonComponent(button.get(), textComponent));
	button->GetComponent<dae::ButtonComponent>()->SetFunction([this, isCoop, isVersus]
		{
			if (isCoop)
			{
				Sleep(750);
				CreateLevel2(*dae::SceneManager::GetInstance().GetScene(2).get(), true, false);
				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(5).get());
			}
			else if (isVersus)
			{
				Sleep(750);
				CreateLevel2(*dae::SceneManager::GetInstance().GetScene(5).get(), false, true);

				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(8).get());
			}
			else
			{
				Sleep(1000);
				CreateLevel2(*dae::SceneManager::GetInstance().GetScene(8).get(), false, false);
				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(2).get());
			}

		});
	scene2.Add(button);


}

void TronGame::CreateLevel2(dae::Scene& scene2, bool IsCoop, bool IsVersus) const
{

	const auto tank1{ dae::InputManager::GetInstance().AddPlayer(true) };

	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->AddComponent(new ControllerComponent(Tank.get(), Tank->GetComponent<dae::TankComponent>()));
	Tank->SetPosition(70, 100);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));

	Tank2->SetPosition(300, 305);


	HandleInputPlayer(Tank, 0);

	if (IsCoop)
	{

		const auto Tank3{ std::make_shared<dae::GameObject>() };
		SDL_Rect src2{ 256,0,32,32 };
		Tank3->AddComponent(new SpriteComponent(Tank3.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
		Tank3->AddComponent(new dae::RigidBody(Tank3.get()));
		Tank3->AddComponent(new CollisionComponent(Tank3.get(), 25));
		Tank3->AddComponent(new dae::TankComponent(Tank3.get()));
		Tank3->AddComponent(new BulletManager(Tank3.get()));
		Tank3->SetPosition(300, 100);
		scene2.Add(Tank3);
		HandleInputPlayer(Tank3, 1);
	}

	if (IsVersus)
	{
		HandleInputPlayer(Tank2, 1);
	}

	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	CreateLivesText(scene2, Tank, { 0,0,0 });
	CreateScoreText(scene2, Tank, { 200,0,0 });
	if (IsVersus)
	{
		CreateLivesText(scene2, Tank2, { 400,0,0 });
		CreateScoreText(scene2, Tank2, { 600,0,0 });
	}

	const auto button = std::make_shared<dae::GameObject>();
	auto textComponent = new dae::TextComponent(button.get(), "Skip", font);
	textComponent->SetPosition({ 300, 550,0 });
	button->AddComponent(textComponent);
	button->AddComponent(new dae::ButtonComponent(button.get(), textComponent));
	button->GetComponent<dae::ButtonComponent>()->SetFunction([this, IsCoop, IsVersus]
		{
			if (IsCoop)
			{
				Sleep(750);
				CreateLevel3(*dae::SceneManager::GetInstance().GetScene(2).get(), true, false);
				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(6).get());
			}
			else if (IsVersus)
			{
				Sleep(750);
				CreateLevel3(*dae::SceneManager::GetInstance().GetScene(5).get(), false, true);

				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(9).get());
			}
			else
			{
				Sleep(1000);
				CreateLevel3(*dae::SceneManager::GetInstance().GetScene(8).get(), false, false);
				dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(3).get());
			}

		});
	scene2.Add(button);

}

void TronGame::CreateLevel3(dae::Scene& scene2, bool IsCoop, bool IsVersus) const
{


	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->AddComponent(new ControllerComponent(Tank.get(), Tank->GetComponent<dae::TankComponent>()));

	Tank->SetPosition(70, 100);


	HandleInputPlayer(Tank, 0);

	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));
	Tank2->AddComponent(new BulletManager(Tank2.get()));

	Tank2->SetPosition(300, 300);

	if (IsCoop)
	{

		const auto Tank3{ std::make_shared<dae::GameObject>() };
		SDL_Rect src2{ 256,0,32,32 };
		Tank3->AddComponent(new SpriteComponent(Tank3.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
		Tank3->AddComponent(new dae::RigidBody(Tank3.get()));
		Tank3->AddComponent(new CollisionComponent(Tank3.get(), 25));
		Tank3->AddComponent(new dae::TankComponent(Tank3.get()));
		Tank3->AddComponent(new BulletManager(Tank3.get()));
		Tank3->SetPosition(300, 100);
		scene2.Add(Tank3);
		HandleInputPlayer(Tank3, 1);
	}

	if (IsVersus)
	{
		HandleInputPlayer(Tank2, 1);
	}

	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	CreateLivesText(scene2, Tank, { 0,0,0 });
	CreateScoreText(scene2, Tank, { 200,0,0 });
	if (IsVersus)
	{
		CreateLivesText(scene2, Tank2, { 400,0,0 });
		CreateScoreText(scene2, Tank2, { 600,0,0 });
	}

	const auto button = std::make_shared<dae::GameObject>();
	auto textComponent = new dae::TextComponent(button.get(), "Skip", font);
	textComponent->SetPosition({ 300, 550,0 });
	button->AddComponent(textComponent);
	button->AddComponent(new dae::ButtonComponent(button.get(), textComponent));
	button->GetComponent<dae::ButtonComponent>()->SetFunction([this]
		{

			Sleep(1000);

			dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());

		});
	scene2.Add(button);

}

void TronGame::CreateStartScreen(dae::Scene& scene) const
{
	dae::ServiceLocator::GetSoundSystem()->RegisterSound("../Data/Sound/Start.wav");

	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);
	const auto startScreen = std::make_shared<dae::GameObject>();
	SDL_Rect src{ 0,0,500,500 };
	startScreen->AddComponent(new SpriteComponent(startScreen.get(), Sprite("tron.png", 1, 1, src), { 100,50,500,500 }));

	scene.Add(startScreen);

	const auto button = std::make_shared<dae::GameObject>();
	auto textComponent = new dae::TextComponent(button.get(), "Single Player", font);
	textComponent->SetPosition({ 300, 550,0 });
	button->AddComponent(textComponent);
	button->AddComponent(new dae::ButtonComponent(button.get(), textComponent));
	button->GetComponent<dae::ButtonComponent>()->SetFunction([this]
		{

			Sleep(500);
			CreateLevel1(*dae::SceneManager::GetInstance().GetScene(1), false, false);
			dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(1).get());
		});
	scene.Add(button);

	auto button2 = std::make_shared<dae::GameObject>();
	textComponent = new dae::TextComponent(button2.get(), "COOP", font);
	textComponent->SetPosition({ 300, 580,0 });
	button2->AddComponent(textComponent);
	button2->AddComponent(new dae::ButtonComponent(button2.get(), textComponent));
	button2->GetComponent<dae::ButtonComponent>()->SetFunction([this]
		{
			CreateLevel1(*dae::SceneManager::GetInstance().GetScene(4), true, false);
			dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(4).get());
		});

	auto button3 = std::make_shared<dae::GameObject>();
	textComponent = new dae::TextComponent(button2.get(), "VERSUS", font);
	textComponent->SetPosition({ 300, 610,0 });
	button3->AddComponent(textComponent);
	button3->AddComponent(new dae::ButtonComponent(button2.get(), textComponent));
	button3->GetComponent<dae::ButtonComponent>()->SetFunction([this]
		{
			CreateLevel1(*dae::SceneManager::GetInstance().GetScene(7), false, true);
			dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(7).get());

		});


	scene.Add(button);
	scene.Add(button2);
	scene.Add(button3);
}

void TronGame::LoadGame() const
{
	const auto p1{ dae::InputManager::GetInstance().AddPlayer() };
	const auto p2{ dae::InputManager::GetInstance().AddPlayer() };
	const auto p1K{ dae::InputManager::GetInstance().AddPlayer(true) };
	const auto p2K{ dae::InputManager::GetInstance().AddPlayer(true) };

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto& scene2 = dae::SceneManager::GetInstance().CreateScene("Level1");
	auto& scene3 = dae::SceneManager::GetInstance().CreateScene("Level2");
	auto& scene4 = dae::SceneManager::GetInstance().CreateScene("Level3");
	auto& scene5 = dae::SceneManager::GetInstance().CreateScene("Level1COOP");
	auto& scene6 = dae::SceneManager::GetInstance().CreateScene("Level2COOp");
	auto& scene7 = dae::SceneManager::GetInstance().CreateScene("Level3COOP");
	auto& scene8 = dae::SceneManager::GetInstance().CreateScene("Level1VERSUS");
	auto& scene9 = dae::SceneManager::GetInstance().CreateScene("Level2VERSUS");
	auto& scene10 = dae::SceneManager::GetInstance().CreateScene("Level3VERSUS");

	dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(0).get());
	bool r = dae::LevelParser::ParseOBJ("../Data/Level/Level01.txt", scene2, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene3, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene4, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level01.txt", scene5, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene6, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene7, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level01.txt", scene8, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene9, false);
	r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene10, false);




	CreateStartScreen(scene);

	CreateLevel2(scene3, false, false);
	CreateLevel3(scene4, false, false);

	CreateLevel2(scene6, true, false);
	CreateLevel3(scene7, true, false);

	CreateLevel2(scene9, false, true);
	CreateLevel3(scene10, false, true);

}
