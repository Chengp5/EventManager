#pragma once
#include "EventType.h"
#include "Delegate.h"
#include <string>
#include <list>
#include <iostream>
namespace eventmanager {
	template<class T>
	class Event
	{
	public:
		Event() = default;
		Event(EventType t, std::string Ename) :eType(t), name(Ename) {
		}
		void AddListener(const Delegate<T>& d) {
			if (find(DelegateList.begin(), DelegateList.end(), d) == DelegateList.end())
			{
				DelegateList.push_back(d);
				std::cout << "new Delegate in\n";
			}
		}
		void AddListener(Delegate<T>&& d) {
			if (find(DelegateList.begin(), DelegateList.end(), d) == DelegateList.end())
			{
				DelegateList.push_back(std::forward(d));
				std::cout << "new Delegate in\n";
			}
		}
		void RemoveListener(Delegate<T>&& d)
		{
			auto it = find(DelegateList.begin(), DelegateList.end(), d);
			if (it != DelegateList.end())
			{
				DelegateList.erase(it);
				std::cout << "new Delegate out\n";
			}
		}
		void RemoveListener(const Delegate<T>& d)
		{
			auto it = find(DelegateList.begin(), DelegateList.end(), d);
				if (it != DelegateList.end())
				{
					DelegateList.erase(it);
					std::cout << "new Delegate out\n";
				}
		}
		template<typename...Args>
		void NotifyAll(Args&&...args) {
			for (auto& d : DelegateList)
			{
				d.Invoke(name, std::forward<Args>(args)...);
			}
		}
	protected:
	private:
		std::list<eventmanager::Delegate<T>> DelegateList;
		EventType eType;
		std::string name;
	};
}

