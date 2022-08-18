#include "TronGame.h"

#include "BulletManager.h"
#include "ButtonComponent.h"
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
#include "LevelParser.h"
#include "LivesComponent.h"
#include "ScoreComponent.h"
#include "TankComponent.h"
#include "WallComponent.h"


void TronGame::CreateLevel1(dae::Scene& scene2) const
{
	const auto tank1{ dae::InputManager::GetInstance().AddPlayer() };
	const auto tank2{ dae::InputManager::GetInstance().AddPlayer(true) };


	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->SetPosition(70, 100);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));

	Tank2->SetPosition(300, 300);


	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_SPACE, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);


	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_E, std::make_shared<RotateCommand>(Tank.get(), true,false), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_R, std::make_shared<RotateCommand>(Tank.get(),true, true), tank1, dae::InputManager::EInputState::Down);



	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	const auto lives{ std::make_shared<dae::GameObject>() };
	auto livesText = new dae::TextComponent(lives.get(), "Lives:", font);
	lives->AddComponent(livesText);
	auto livesObserver = new dae::LivesComponent(lives.get(), Tank->GetComponent<dae::TankComponent>(), livesText);
	lives->AddComponent(livesObserver);
	scene2.Add(lives);

	const auto score{ std::make_shared<dae::GameObject>() };
	auto scoreText = new dae::TextComponent(score.get(), "Score:", font);
	scoreText->SetPosition({ 200,0 ,0});
	score->AddComponent(scoreText);
	auto ScoreObserver = new ScoreComponent(score.get(), Tank->GetComponent<dae::TankComponent>(), scoreText);
	score->AddComponent(ScoreObserver);
	Tank->GetComponent<dae::TankComponent>()->AddObserver(ScoreObserver);

	
	scene2.Add(score);
}

void TronGame::CreateLevel2(dae::Scene& scene2) const
{

	const auto tank1{ dae::InputManager::GetInstance().AddPlayer() };
	const auto tank2{ dae::InputManager::GetInstance().AddPlayer(true) };


	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->SetPosition(70, 100);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));

	Tank2->SetPosition(300, 300);


	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_SPACE, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);


	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	const auto lives{ std::make_shared<dae::GameObject>() };
	auto livesText = new dae::TextComponent(lives.get(), "Lives:", font);
	lives->AddComponent(livesText);
	auto livesObserver = new dae::LivesComponent(lives.get(), Tank->GetComponent<dae::TankComponent>(), livesText);
	lives->AddComponent(livesObserver);
	scene2.Add(lives);

	const auto score{ std::make_shared<dae::GameObject>() };
	auto scoreText = new dae::TextComponent(score.get(), "Score:", font);
	scoreText->SetPosition({ 200,0 ,0 });
	score->AddComponent(scoreText);
	auto ScoreObserver = new ScoreComponent(score.get(), Tank->GetComponent<dae::TankComponent>(), scoreText);
	score->AddComponent(ScoreObserver);
	Tank->GetComponent<dae::TankComponent>()->AddObserver(ScoreObserver);


	scene2.Add(score);
}

void TronGame::CreateLevel3(dae::Scene& scene2) const
{
	const auto tank1{ dae::InputManager::GetInstance().AddPlayer() };
	const auto tank2{ dae::InputManager::GetInstance().AddPlayer(true) };


	const auto Tank{ std::make_shared<dae::GameObject>() };

	SDL_Rect src{ 352,0,32,32 };
	Tank->AddComponent(new SpriteComponent(Tank.get(), Sprite("TronSprite.png", 1, 1, src), { 0,0,25,25 }));
	Tank->AddComponent(new dae::RigidBody(Tank.get()));
	Tank->AddComponent(new CollisionComponent(Tank.get(), 25));
	Tank->AddComponent(new dae::TankComponent(Tank.get()));
	Tank->AddComponent(new BulletManager(Tank.get()));
	Tank->SetPosition(70, 100);


	const auto Tank2{ std::make_shared<dae::GameObject>() };

	SDL_Rect src2{ 288,0,32,32 };
	Tank2->AddComponent(new SpriteComponent(Tank2.get(), Sprite("TronSprite.png", 1, 1, src2), { 0,0,25,25 }));
	Tank2->AddComponent(new dae::RigidBody(Tank2.get()));
	Tank2->AddComponent(new CollisionComponent(Tank2.get(), 25));
	Tank2->AddComponent(new dae::TankComponent(Tank2.get()));

	Tank2->SetPosition(300, 300);


	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Down);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_SPACE, std::make_shared<AttackCommand>(Tank.get()), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Left), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Right), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Up), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::Down), tank1, dae::InputManager::EInputState::Pressed);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADLeft, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADRight, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADUp, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(dae::XboxController::Button::ButtonDPADDown, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_A, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_D, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_W, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);
	dae::InputManager::GetInstance().AddCommand(SDL_SCANCODE_S, std::make_shared<MoveCommand>(Tank.get(), dae::TankComponent::TankState::idle), tank1, dae::InputManager::EInputState::Up);


	auto font = dae::ResourceManager::GetInstance().LoadFont("BurgerTimeFont.otf", 20);

	scene2.Add(Tank);
	scene2.Add(Tank2);


	const auto lives{ std::make_shared<dae::GameObject>() };
	auto livesText = new dae::TextComponent(lives.get(), "Lives:", font);
	lives->AddComponent(livesText);
	auto livesObserver = new dae::LivesComponent(lives.get(), Tank->GetComponent<dae::TankComponent>(), livesText);
	lives->AddComponent(livesObserver);
	scene2.Add(lives);

	const auto score{ std::make_shared<dae::GameObject>() };
	auto scoreText = new dae::TextComponent(score.get(), "Score:", font);
	scoreText->SetPosition({ 200,0 ,0 });
	score->AddComponent(scoreText);
	auto ScoreObserver = new ScoreComponent(score.get(), Tank->GetComponent<dae::TankComponent>(), scoreText);
	score->AddComponent(ScoreObserver);
	Tank->GetComponent<dae::TankComponent>()->AddObserver(ScoreObserver);


	scene2.Add(score);
}

void TronGame::CreateStartScreen(dae::Scene& scene) const
{
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
	button->GetComponent<dae::ButtonComponent>()->SetFunction([]
	{
		dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(1).get());
	});
	scene.Add(button);

	auto button2 = std::make_shared<dae::GameObject>();
	textComponent = new dae::TextComponent(button2.get(), "COOP", font);
	textComponent->SetPosition({ 300, 580,0 });
	button2->AddComponent(textComponent);
	button2->AddComponent(new dae::ButtonComponent(button2.get(), textComponent));
	button2->GetComponent<dae::ButtonComponent>()->SetFunction([]
	{
		dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(4).get());
	});

	auto button3 = std::make_shared<dae::GameObject>();
	textComponent = new dae::TextComponent(button2.get(), "VERSUS", font);
	textComponent->SetPosition({ 300, 610,0 });
	button3->AddComponent(textComponent);
	button3->AddComponent(new dae::ButtonComponent(button2.get(), textComponent));
	button3->GetComponent<dae::ButtonComponent>()->SetFunction([]
	{
		dae::SceneManager::GetInstance().SetActiveScene(dae::SceneManager::GetInstance().GetScene(7).get());
	});



	scene.Add(button);
	scene.Add(button2);
	scene.Add(button3);
}

void TronGame::LoadGame() const
{


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
	bool r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene2, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene3, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene4, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level01.txt", scene5, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene6, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene7, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level01.txt", scene8, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level02.txt", scene9, false);
	 r = dae::LevelParser::ParseOBJ("../Data/Level/Level03.txt", scene10, false);
	 



	CreateStartScreen(scene);

	CreateLevel1(scene2);















}
