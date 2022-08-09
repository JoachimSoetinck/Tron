#include "MiniginPCH.h"
#include "Keyboard.h"



class KeyBoard::pImpl final
{
	bool m_CurrentState[256]{};
	bool m_PreviousState[256]{};
	int m_ControllerIndex{};
	
public:
	pImpl(int controllerNr)
		:m_ControllerIndex(controllerNr)
	{
		ZeroMemory(&m_CurrentState, sizeof(bool) * 256);
		ZeroMemory(&m_PreviousState, sizeof(bool) * 256);
	}
	~pImpl() = default;

	void Update()
	{
		CopyMemory(&m_CurrentState, &m_PreviousState, sizeof(bool) * 256);
		ZeroMemory(&m_PreviousState, sizeof(bool) * 256);

		const Uint8* pState = SDL_GetKeyboardState(nullptr);
		for (size_t i = 0; i < 256; ++i)
		{
			m_CurrentState[i] = pState[i];
		}
	}

	bool IsDown(SDL_Scancode scancode)const
	{
		return m_CurrentState[scancode];
	}
	bool IsUp(SDL_Scancode scancode)const
	{
		return m_PreviousState[scancode] && !m_CurrentState[scancode];
	}
	bool IsPressed(SDL_Scancode scancode)const
	{
		return !m_PreviousState[scancode] && m_CurrentState[scancode];
	}


};

KeyBoard::KeyBoard(int controllerNr)
	:m_pImpl(new pImpl(controllerNr))
{
}

KeyBoard::~KeyBoard()
{
	delete m_pImpl;
	m_pImpl = nullptr;
}

void KeyBoard::Update() const
{
	m_pImpl->Update();
}

bool KeyBoard::IsDown(SDL_Scancode scancode) const
{
	return m_pImpl->IsDown(scancode);
}

bool KeyBoard::IsUp(SDL_Scancode scancode) const
{
	return m_pImpl->IsUp(scancode);
}

bool KeyBoard::IsPressed(SDL_Scancode scancode) const
{
	return m_pImpl->IsPressed(scancode);
}