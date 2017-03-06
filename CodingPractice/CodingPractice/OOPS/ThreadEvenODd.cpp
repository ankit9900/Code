#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>


// A program to print even and odd by two threads

using namespace std;
class Test {
	thread t1, t2;
	mutex m;
	condition_variable_any cv;
	bool oddDone;
	bool evenDone;
public:
	Test() {
		oddDone = false;
		evenDone = true;
		t1 = thread(&Test::printOdd, this);
		t2 = thread(&Test::printEven, this);
		t1.join();
		t2.join();
	}
	void printOdd() {
		int i = 1;
		while (i <= 30) {
			m.lock();
			cv.wait(m, [this]{return this->evenDone; });
			cout << "From ODD thread "<< i << endl;
			m.unlock();
			oddDone = true;
			evenDone = false;
			i = i + 2;
			cv.notify_all();
		}
	}
	void printEven(){
		int i = 2;
		while (i <= 30) {
			m.lock();
			cv.wait(m, [this]{return this->oddDone; });
			cout <<"From EVEN thread " <<i << endl;
			m.unlock();
			evenDone = true;
			oddDone = false;
			i = i + 2;
			cv.notify_all();
		}
	}
	
};
int main() {
	Test t;

	system("pause");
	return 0;

}