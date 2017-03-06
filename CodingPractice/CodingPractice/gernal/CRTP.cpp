#include <iostream>
using namespace std;
template <typename T>
class base {
public:
	void test() {
		static_cast<T*>(this)->test();
	}
	void baseMain() {
		cout << "Base main" << endl;
	}
};

class derived : public base < derived >
{
public:
	void test() {
		cout << "Example of CRTP: Without vtable, drived class function called " << endl;
	}
};

int main() {
	base<derived>* b = new derived;
	b->test();
	b->baseMain();
	system("pause");
	return 0;
}
/**********************************Polymorphic copy constructor ***************
// Base class has a pure virtual function for cloning
class Shape {
public:
virtual ~Shape() {};
virtual Shape *clone() const = 0;
};
// This CRTP class implements clone() for Derived
template <typename Derived>
class Shape_CRTP : public Shape {
public:
virtual Shape *clone() const {
return new Derived(static_cast<Derived const&>(*this));
}
};

// Nice macro which ensures correct CRTP usage
#define Derive_Shape_CRTP(Type) class Type: public Shape_CRTP<Type>

// Every derived class inherits from Shape_CRTP instead of Shape
Derive_Shape_CRTP(Square) {};
Derive_Shape_CRTP(Circle) {};

*********************************************************************************/