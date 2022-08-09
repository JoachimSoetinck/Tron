#include "WallComponent.h"

#include "Renderer.h"

WallComponent::WallComponent(dae::GameObject* object, SDL_Rect wallInfo):
BaseComponent(object),
m_WallInfo{wallInfo}
{
}

void WallComponent::Render() const
{
	dae::Renderer::GetInstance().RenderRectangle(m_WallInfo);
}

void WallComponent::Update()
{
}

void WallComponent::FixedUpdate()
{
}
