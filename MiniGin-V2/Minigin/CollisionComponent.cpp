#include "MiniginPCH.h"
#include "CollisionComponent.h"

#include "GameObject.h"
#include "Renderer.h"


void CollisionComponent::Update()
{
}

void CollisionComponent::FixedUpdate()
{
}


void CollisionComponent::Render() const
{
#ifdef _DEBUG
       const auto pos = GetGameObject()->GetLocalPosition();
        const SDL_Rect CollisionBox{ static_cast<int>(m_CollisionBox.x + pos.x),static_cast<int>(m_CollisionBox.y + pos.y),m_CollisionBox.w,m_CollisionBox.h };
        dae::Renderer::GetInstance().DrawRectangle(CollisionBox, m_Color);

#endif
}

bool CollisionComponent::IsOverlapping(const CollisionComponent* collision2) const
{
    //https://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other
    //need to know Current Position Rect
    const auto objPos = GetGameObject()->GetLocalPosition();
    const SDL_Rect collisionBoxOne{ static_cast<int>(m_CollisionBox.x + objPos.x),static_cast<int>(m_CollisionBox.y + objPos.y),m_CollisionBox.w,m_CollisionBox.h };


    const auto otherObjPos = collision2->GetGameObject()->GetLocalPosition();
    const SDL_Rect other = collision2->GetCollisionBox();
    const SDL_Rect otherColPos{ static_cast<int>(other.x + otherObjPos.x),static_cast<int>(other.y + otherObjPos.y),other.w,other.h };

    const SDL_Point l1{ otherColPos.x,otherColPos.y + otherColPos.h }, r1{ otherColPos.x + otherColPos.w, otherColPos.y };

    const SDL_Point l2{ collisionBoxOne.x,collisionBoxOne.y + collisionBoxOne.h }, r2{ collisionBoxOne.x + collisionBoxOne.w, collisionBoxOne.y };


   /* SDL_Rect intersect{};
    auto isOverlapping = SDL_IntersectRect(&otherColPos,&m_CollisionBox ,&intersect );
    return isOverlapping;*/

    return !(l1.x >= r2.x || l2.x >= r1.x || l1.y <= r2.y || l2.y <= r1.y);

    
}





CollisionComponent::CollisionComponent(dae::GameObject* object, SDL_Rect rect): BaseComponent(object),
m_CollisionBox{rect}
{
}

CollisionComponent::CollisionComponent(dae::GameObject* object, int size) : BaseComponent(object)
, m_CollisionBox({ 0, 0,size,size })
{
}

CollisionComponent::~CollisionComponent()
{

}
