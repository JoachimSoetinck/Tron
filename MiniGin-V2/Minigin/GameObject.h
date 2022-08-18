#pragma once
#include "Transform.h"
#include "BaseComponent.h"
#include "MiniginPCH.h"
#include <vector>


namespace dae
{
	class Texture2D;

	class GameObject final
	{
	public:
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render() const;


	
		glm::vec3 GetLocalPosition() const { return m_Transform.GetLocalPosition(); }
		glm::vec3 GetWorldPosition() { return m_Transform.GetWorldPosition(); }
		void SetPosition(float x, float y);
		void MovePosition(float x, float y = 0);

		BaseComponent* AddComponent(BaseComponent* component);
		template <typename T> T* GetComponent() const;

		template <typename T> void RemoveComponent(BaseComponent* pComp);

		
		dae::GameObject* GetParent() const;

		std::vector<std::shared_ptr<dae::GameObject>> GetChildren() const;
	
		void RemoveChild(dae::GameObject* go);
		void AddChild(std::shared_ptr<dae::GameObject> go, bool keepTransform = false);

		GameObject() :m_Transform(this){}
		virtual ~GameObject();

	
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
		void SetParent(dae::GameObject* parent, bool keepWorldPosition = false);

	private:
		

		Transform m_Transform;
		std::vector<BaseComponent*> m_pComponents{};

		std::vector<std::shared_ptr<GameObject>> m_pChildren{};
		dae::GameObject* m_pParent{ nullptr };
	};


	inline BaseComponent* GameObject::AddComponent(BaseComponent* component)
	{
		m_pComponents.emplace_back(component);
		return component;
	}

	template<typename T>
	inline T* GameObject::GetComponent() const
	{
		for (auto comp : m_pComponents)
		{
			if (typeid(*comp) == typeid(T))
			{
				return static_cast<T*>(comp);
			}
		}
		return nullptr;
	}

	template<typename T>
	inline void GameObject::RemoveComponent(BaseComponent* pComp)
	{
		m_pComponents.erase(std::remove(m_pComponents.begin(), m_pComponents.end(), pComp));
	}
}