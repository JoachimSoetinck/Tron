#pragma once
#include "GameObject.h"
#include "Minigin.h"

class TronGame : public dae::Minigin
{
public:
	
	void CreateStartScreen(dae::Scene& scene) const;
	void LoadGame() const override;

private:
	void CreateLevel1(dae::Scene& scene2) const;
	void CreateLevel2(dae::Scene& scene2) const;
	void AddControlsTank(std::shared_ptr<dae::GameObject> Tank, int tank1) const;
	void CreateLevel3(dae::Scene& scene2) const;
	

};


