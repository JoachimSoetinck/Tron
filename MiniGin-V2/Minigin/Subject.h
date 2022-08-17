#pragma once
#include <vector>

#include "Enums.h"
#include "Observer.h"
#include "GameObject.h"

namespace dae
{
	class Subject 
	{


	public:
		Subject() = default;
		virtual ~Subject();
		void AddObserver(Observer* o);
		void RemoveObserver(Observer* o);
		void Notify(Event eventType, GameObject& object);

		template <class T>
		T GetObserver()
		{
			const type_info& ti = typeid(T);
			for (std::shared_ptr<Observer> obs : m_pObservers)
			{
				if (obs && typeid(std::shared_ptr<Observer>) == ti)
					return static_cast<T>(obs);
			}
			return nullptr;
		}

		
		void NotifyAllObservers(  Event event);


	private:
		std::vector<Observer*> m_pObservers;
	};
}


