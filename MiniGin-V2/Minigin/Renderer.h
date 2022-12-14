#pragma once
#include "Singleton.h"


namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
		SDL_Renderer* m_Renderer{};
		SDL_Window* m_Window{};
		SDL_Color m_clearColor{};	
	public:
		void Init(SDL_Window* window);
		void Render() const;
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& srcRect, const SDL_Rect& dstRect, const double& angle, bool flipped) const;
		void RenderTexture(const Texture2D& texture, int x, int y) const;
		void RenderTexture(const Texture2D& texture, float x, float y, float width, float height) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& srcRect, float x, float y) const;
		void RenderTexture(const Texture2D& texture, const SDL_Rect& srcRect, int x, int y) const;
		void RenderRectangle(const SDL_Rect& rect, SDL_Color color = { 255,255,255,1 }) const;
		void DrawRectangle(const SDL_Rect& rect, SDL_Color color = { 255,255,255,1 }) const;
		void DrawLine(int x1, int y1, int x2, int y2)const;
		void RenderPoint(const glm::vec2 point);

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }

		const SDL_Color& GetBackgroundColor() const { return m_clearColor; }
		void SetBackgroundColor(const SDL_Color& color) { m_clearColor = color; }
		
	private:
		
	};
}

