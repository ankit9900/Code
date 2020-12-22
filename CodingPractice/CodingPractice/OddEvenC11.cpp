#include <condition_variable>
#include <mutex>
#include <iostream>
#include <algorithm>
#include <thread>
// This program uses two threads. One thread prints odd and other even
// To sync two threads, we use one mutex and one cv
// cv uses unique lock object
// create unique lock object using mutex
// cv wait on lock till condition met


// if one threads send notify below happens
// cv wait will release lock and checks if condition is met
// if condition is met it will proceed further
// if condition is not met it will lock itself again, so that other thread can continue.


using namespace std;

class OddEven {
	condition_variable v;
	mutex m;
	int x;
	int y;
	int N;
	int i;
public:
	
	OddEven(int k)
	{
		x = 0;
		y = 1;
		N = k;
		i = 0;
	}
	void odd()
	{
		while (x < N)
		{
			unique_lock<mutex>mlock1(m);
			v.wait(mlock1, [this] {return i == 1; });
			cout << y;
			y += 2;
			i = 0;
			v.notify_one();
		}
	}

	void even()
	{
		while (x < N)
		{
			unique_lock<mutex>mlock2(m);
			v.wait(mlock2, [this] {return i == 0; });
			cout << x;
			x += 2;
			i = 1;
			v.notify_one();
		}
	}


};
	int main()
	{
		OddEven t(20);
		thread t1(&OddEven::even, &t);
		thread t2(&OddEven::odd, &t);
		t1.join();
		t2.join();

		return 0;
	}
