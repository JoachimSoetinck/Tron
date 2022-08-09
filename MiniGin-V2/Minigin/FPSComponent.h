#pragma once
#include "BaseComponent.h"
#include "TextComponent.h"


namespace dae {
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent(std::shared_ptr<GameObject> object);
		virtual ~FPSComponent() override = default;
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(BaseComponent&& other) noexcept = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) noexcept = delete;

		virtual void Update() override;
		virtual void Render() const override;

	private:
		TextComponent* m_Text;
		
		float m_AccumulatedTime = 0;
		std::string m_text;
	};
}



