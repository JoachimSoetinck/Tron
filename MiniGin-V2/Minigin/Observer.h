#pragma once
#include "Enums.h"
#include "GameObject.h"

namespace dae
{
	class Observer
	{
	public:
		Observer() = default;
		virtual ~Observer() = default;
		Observer(const Observer& other) = delete;
		Observer(Observer&& other) noexcept = delete;
		Observer& operator=(const Observer& other) = delete;
		Observer& operator=(Observer&& other) noexcept = delete;

		virtual void OnNotify( Event event) = 0;
	};
}


