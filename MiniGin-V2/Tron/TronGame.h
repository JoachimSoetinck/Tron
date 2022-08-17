#pragma once
#include "GameObject.h"
#include "Minigin.h"

class TronGame : public dae::Minigin
{
public:
	void CreateLevel1(dae::Scene& scene2) const;
	void LoadGame() const override;

private:

	void AddWall(dae::Scene& scene, SDL_Rect wall) const;

};


