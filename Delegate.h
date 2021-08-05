#pragma once
#include <functional>
namespace eventmanager {
	//use Delegate to wrap one function object.
	// create one Delegate is as easy as create an function object.
	template<class T>
	class Delegate
	{
	public:
		explicit Delegate(std::function<T>func) :callback(func),signeture(index++) {}
		bool operator==(const Delegate& rhs)
		{
			return signeture == rhs.signeture;
		}
		void AddFunc(std::function<T> func)
		{
			callback = func;
		}
		template<typename...Args>
		void Invoke(Args&&...args)
		{
			callback(std::forward<Args>(args)...);
		}
	protected:
	private:
		static long long index;
		//use signature to identify each Delegate
		long long signeture;
		std::function<T> callback;
	};
	template<class T>
	long long Delegate<T>::index = 0;
}


