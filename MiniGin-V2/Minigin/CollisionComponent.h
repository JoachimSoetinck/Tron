#pragma once
#include "BaseComponent.h"

class CollisionComponent final: public dae::BaseComponent
{
public:
	CollisionComponent(dae::GameObject* object, SDL_Rect rect);
	CollisionComponent(dae::GameObject* object, int size);
	~CollisionComponent() override;

	CollisionComponent(const CollisionComponent& other) = delete;
	CollisionComponent(CollisionComponent&& other) noexcept = delete;
	CollisionComponent& operator=(const CollisionComponent& other) = delete;
	CollisionComponent& operator=(CollisionComponent&& other) noexcept = delete;

	void Update() override;
	void FixedUpdate() override;
	void Render() const override;

	bool IsOverlapping(const CollisionComponent* collisionBox) const;
	bool IsOverlapping(const SDL_Rect collisionBox) const;
	bool IsPointInRect(const glm::vec2& point);

	SDL_Rect GetCollisionBox() const { return m_CollisionBox; }

	void SetCollisionBox(SDL_Rect col) { m_CollisionBox = col; }
	
private:
	SDL_Rect m_CollisionBox{};
	SDL_Color m_Color{ 255,255,255,1 };
};

