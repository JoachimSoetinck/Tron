#pragma once
struct SDL_Texture;
#include "SDL_rect.h"
namespace dae
{
	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */
	class Texture2D
	{
	public:
		SDL_Texture* GetSDLTexture() const;
		explicit Texture2D(SDL_Texture* texture);
		~Texture2D();

		Texture2D(const Texture2D&) = delete;
		Texture2D(Texture2D&&) = delete;
		Texture2D& operator= (const Texture2D&) = delete;
		Texture2D& operator= (const Texture2D&&) = delete;

		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }
		

	private:
		SDL_Texture* m_Texture;

		int m_Width{};
		int m_Height{};
		
	};
}
