#include <iostream>
#include <mutex>
using namespace std;

class Singleton {
	Singleton(){};
	Singleton(const Singleton&){};
	Singleton& operator=(const Singleton&){};
	static mutex m_mutex;
public:
	static Singleton* m_Instance;
	static Singleton* createInstance() {
		if (m_Instance == nullptr){
			m_mutex.lock();
			if (m_Instance == nullptr) {
				m_Instance = new Singleton();
				return m_Instance;
			}
		}
		return m_Instance;
	}
	void show(){
		cout << "This is Thread safe Singleton " << endl;
	}
};
Singleton* Singleton::m_Instance = nullptr;
mutex Singleton::m_mutex;

//------------------2nd Implementation-------------//
class Singleton2 {
	Singleton2(){};
	Singleton2(const Singleton2&){};
	Singleton2& operator=(const Singleton2&){};
public:
	static Singleton2* m_Instance;
	static Singleton2* createInstance() {
		if (m_Instance == nullptr){
			static mutex m_mutex;
			m_mutex.lock();
			if (m_Instance == nullptr) {
				m_Instance = new Singleton2();
				return m_Instance;
			}
		}
		return m_Instance;
	}
	void show(){
		cout << "This is Thread safe Singleton 2nd imlementation " << endl;
	}
};
Singleton2* Singleton2::m_Instance = nullptr;

//------------------3nd Implementation-------------//
class Singleton3 {
	Singleton3(){};
	~Singleton3(){};
	Singleton3(const Singleton3&){};
	Singleton3& operator=(const Singleton3&){};
public:
	
	static Singleton3& createInstance() {
		static Singleton3 instance ;
		return instance;
	}
	void show(){
		cout << "This is Thread safe Singleton 3rd imlementation" << endl;
	}
};
int main() {
	Singleton* obj = Singleton::createInstance();
	obj->show();
	Singleton* obj2 = Singleton::createInstance();
	cout << obj << endl;
	cout << obj2 << endl;

	// ---2nd Implementation----//
	Singleton2* obj3 = Singleton2::createInstance();
	obj3->show();
	Singleton2* obj4 = Singleton2::createInstance();
	cout << obj3 << endl;
	cout << obj4 << endl;

	// --3rd Implementation----//
	Singleton3& obj5 = Singleton3::createInstance();
	obj5.show();
	Singleton3& obj6 = Singleton3::createInstance();
	cout << &obj5 << endl;
	cout << &obj6 << endl;
	system("pause");
	return 0;
}