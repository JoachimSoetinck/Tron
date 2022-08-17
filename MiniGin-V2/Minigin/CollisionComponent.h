#pragma once
#include "BaseComponent.h"

class CollisionComponent final: public dae::BaseComponent
{
public:
	enum class Side {
		Left,
		Right,
		Up,
		Down
	};

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
	bool IsOverlapping(SDL_Rect collisionBox) const;


	SDL_Rect GetCollisionBox() const { return m_CollisionBox; }

	void SetCollisionBox(SDL_Rect col) { m_CollisionBox = col; }

	Side SideDetection(const CollisionComponent* collisionBox) const;

	SDL_Point GetCenter() const { return { m_CollisionBox.x + m_CollisionBox.w / 2, m_CollisionBox.y + m_CollisionBox.h / 2 }; }
	
private:
	SDL_Rect m_CollisionBox{};
	SDL_Color m_Color{ 255,255,255,1 };
};

