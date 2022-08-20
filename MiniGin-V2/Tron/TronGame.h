#pragma once
#include "GameObject.h"
#include "Minigin.h"

class TronGame : public dae::Minigin
{
public:
	
	void CreateStartScreen(dae::Scene& scene) const;
	void LoadGame() const override;

private:
	void HandleInputPlayer(std::shared_ptr<dae::GameObject> Tank, int tank1) const;
	void CreateLivesText(dae::Scene& scene2, std::shared_ptr<dae::GameObject> Tank, glm::vec3 pos) const;
	void CreateScoreText(dae::Scene& scene2, std::shared_ptr<dae::GameObject> Tank, glm::vec3 pos) const;
	void CreateLevel1(dae::Scene& scene2, bool isCoop, bool  isVersus) const;
	void CreateLevel2(dae::Scene& scene2, bool IsCoop, bool IsVersus) const;
	void CreateLevel3(dae::Scene& scene2, bool IsCoop, bool IsVersus) const;


};


