#pragma pack

#include <iostream>
using namespace std;

class Base1 {
public:

	virtual void fun() {
		cout << "Bse" << endl;
	}

};
class Base2 {
public:
	
	virtual void fun() {
		cout << "Bse" << endl;
	}
	
};
class Base3 {
public:

	virtual void fun() {
		cout << "Bse" << endl;
	}

};

class Derived2 : public Base2 , public Base1, public Base3{
public:
	
	virtual void fun23() {
		cout << "der2" << endl;
	}
	virtual void fun() {
		cout << "der2" << endl;
	}
	
};

class Derived3 : public Base2{
public:

	virtual void fun() {
		cout << "der" << endl;
	}

};
class Derived4 {
public:

	virtual void fun() {
		cout << "der" << endl;
	}

};
int main() {
	Derived2 d2;
	Derived3 d3;
	Derived4 d4;
	Base2* bp = &d2;
	bp->fun23();
	cout << sizeof( d2) << endl;
	cout << sizeof(d3) << endl;
	cout << sizeof(d4) << endl;
	
	system("pause");
	return 0;
} ///:~