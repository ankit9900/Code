#include <iostream>
using namespace std;

template <int n> 
struct Fib {
	enum { val = Fib<n-1>::val + Fib<n-2>::val };
};

template<>
struct Fib <1> {
	enum { val = 1 };
};

template <>
struct Fib <0> {
	enum { val = 0 };
};

int main()
{
	cout << Fib<6>::val << endl;

	system("pause");
	return 0;
}

