#include <iostream>
#include <string>
#include <memory>
#include "SmartPtr.h"
using namespace std;

class T {
	string s;
	int x;
public:
	~T() {
		cout << "dtr" << endl;
	}
	
	T() :s(""), x(0){

	}
	T(const T& tt) {
		s = tt.s;
		x = tt.x;
	}
	
	T& operator= (const T & tt) {
		if (this != &tt) {
			s = tt.s;
			x = tt.x;
		}
		return *this;
	}
	T(string ss, int xx) :s(ss), x(xx){

	}
	void show() {
		cout << s << " " << x << endl;
	}
};
int main() {
	{
		
		// Testing Shared and Smart Pointers:
		T* oo = new T();
		shared_ptr<T> sp1 = make_shared<T>("ankit", 10);
		shared_ptr<T> sp2 = sp1;
		shared_ptr<T> sp3 = sp1;
		
		/*weak_ptr<T> wp(sp1);
		weak_ptr<T> wp1(wp);
		weak_ptr<T> wp2(wp);
		*/
		
		cout << "---USE SMART ----" << endl;
	}
	/*{
		cout << "---USE MY OWN SMART POINTER START ----" << endl;
		
		T* obj = new T;
		{
			SmartPtr<T> ss(obj);
		}
		{
			SmartPtr<T> ss2(obj);
		}
		cout << "---USE MY OWN SMART POINTER END----" << endl;
	}*/
	
	system("pause");
	return 0;
}