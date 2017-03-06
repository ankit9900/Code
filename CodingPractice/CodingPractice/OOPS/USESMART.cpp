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
		T p1("ankit", 10);
		T p2= p1;
		shared_ptr<T> sp(new T("ankit",10));
		shared_ptr<T> sp2(new T("ankit", 10));
		shared_ptr<T> sp3(sp2);
		shared_ptr<T> sp4(new T("ankit", 10));
		cout << "---USE SMART ----" << endl;
	}
	{
		cout << "---USE MY OWN SMART POINTER START ----" << endl;
		SmartPtr<T> sp(new T("ankit", 10));
		SmartPtr<T> sp2(new T("ankit", 10));
		SmartPtr<T> sp3(sp2);

		cout << sp3.getRaw() << endl;
		cout << sp2.getRaw() << endl;

		cout << sp3.getRefCount() << endl;
		cout << sp2.getRefCount() << endl;

		sp2.reset();
		cout << sp3.getRefCount() << endl;
		cout << sp2.getRefCount() << endl;

	    SmartPtr<T> sp4(new T("ankit", 10));
		SmartPtr<T> sp5;
		sp5 = sp2;
		sp->show();
		sp5->show();
		SmartPtr<T> sp6(new T("ankit", 10));
		cout << "---USE MY OWN SMART POINTER END----" << endl;
	}
	
	system("pause");
	return 0;
}