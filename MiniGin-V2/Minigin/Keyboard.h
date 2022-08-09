#pragma once
#include "BaseController.h"
class KeyBoard final : public BaseController
{
	class pImpl;
	pImpl* m_pImpl = nullptr;
public:

	KeyBoard(int controllerNr);
	~KeyBoard() override;

	void Update() const override;

	bool IsDown(SDL_Scancode code)const;
	bool IsUp(SDL_Scancode code)const;
	bool IsPressed(SDL_Scancode code)const;
};

