#pragma once
#include "BaseComponent.h"

class WallComponent : public dae::BaseComponent
{
public:
	WallComponent(dae::GameObject* object, SDL_Rect wallInfo);
	~WallComponent() override= default;
	WallComponent(const WallComponent& other) = delete;
	WallComponent(WallComponent&& other) noexcept = delete;
	WallComponent& operator=(const WallComponent& other) = delete;
	WallComponent& operator=(WallComponent&& other) noexcept = delete;

	void Render() const override;
	void Update() override;
	void FixedUpdate() override;

	SDL_Rect GetWallInfo() const{ return m_WallInfo; };

private:
	SDL_Rect m_WallInfo{};


};


