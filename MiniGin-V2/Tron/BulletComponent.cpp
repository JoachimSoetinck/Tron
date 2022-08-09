#include "BulletComponent.h"

BulletComponent::BulletComponent(dae::GameObject* object, const glm::vec2 direction):
BaseComponent(object),
m_NrOfBounces{0},
m_maxNrOfBounces{5},
m_direction{direction}
{
}

void BulletComponent::Render() const
{
}

void BulletComponent::Update()
{
}

void BulletComponent::FixedUpdate()
{
}
