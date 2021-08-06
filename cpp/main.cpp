#include <iostream>
#include "EventCenter.h"
using namespace eventmanager;
using namespace std;
using namespace placeholders;
// test....
class TestClass
{
public:
	TestClass(){}
	//a static function 
	static void smf(string eventName, int arg1)
	{
		cout << "receive event" + eventName << endl;
		cout << "static function\n";
	}
	// a member function
	 void mf1(string eventName, int arg1,float arg2, double arg3)
	{
		cout << "receive event" + eventName << endl;
		cout << "member function\n";
	}
	 // a const member function
	 void mf2(string eventName, int arg1, float arg2, double arg3, string arg4) const
	{
		cout << "receive event" + eventName << endl;
		cout << "const member function\n";
	}
	 ~TestClass() {}

private:

};
void f(string eventName,int arg1, string arg2) {
	cout << "receive event" + eventName << endl;
	cout << "normal function\n";
}
string rtn_f(string eventName)
{
	cout << "receive event" + eventName << endl;
	cout << "normal function with return type \n";
	return "";
}


int main()
{
	TestClass obj;
	//a demo here

	Delegate<void(string, int, string)>  d1(std::bind(&f, _1, _2, _3));
	Delegate<void(string, int)> d2(std::bind(&TestClass::smf, _1, _2));
	Delegate<void(string, int, float, double)> d3(std::bind(&TestClass::mf1, &obj, _1, _2, _3, _4));
	Delegate<void(string, int, float, double, string)> d4(std::bind(&TestClass::mf2, &obj, _1, _2, _3, _4, _5));
	Event<void(string, int, string)> e1(EventType::GAME_START, "game_start");
	e1.AddListener(d1);
	e1.AddListener(d1);
	//e1.RemoveListener(d1);
	Event<void(string, int)> e2(EventType::UI_EVENT_, "UI");
	e2.AddListener(d2);
	//e2.RemoveListener(d2);
	Event<void(string, int, float, double)> e3(EventType::ANIMATION_EVENT_, "Animation");
	e3.AddListener(d3);
	//e3.RemoveListener(d3);
	Event<void(string, int, float, double, string)> e4(EventType::GAME_END, "game_end");
	e4.AddListener(d4);
	//e4.RemoveListener(d4);
	e1.NotifyAll(1,"world");
	e1.RemoveListener(d1);
	e1.NotifyAll(1,"world");
	e2.NotifyAll(1);
	e3.NotifyAll(1,1.0,1.0);
	e4.NotifyAll(1, 1.0, 1.0,"world");

}