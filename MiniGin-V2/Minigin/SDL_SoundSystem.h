#pragma once
#include "SoundSystem.h"

namespace dae
{
	class SDL_SoundSystem final : public SoundSystem
	{
	public:
		SDL_SoundSystem();
		~SDL_SoundSystem();


		SDL_SoundSystem(const SDL_SoundSystem& other) = delete;
		SDL_SoundSystem(SDL_SoundSystem&& other) noexcept = delete;
		SDL_SoundSystem& operator=(const SDL_SoundSystem& other) = delete;
		SDL_SoundSystem& operator=(SDL_SoundSystem&& other) noexcept = delete;

		void Play(const Sound_Id id, const float volume) override;
		void RegisterSound(const Sound_Id, const std::string&) override;

	private:
		class sdl_SoundSystemImpl;
		sdl_SoundSystemImpl* m_pImpl;
	};
}

