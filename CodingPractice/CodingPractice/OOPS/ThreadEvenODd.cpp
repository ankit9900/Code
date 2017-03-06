#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>


// A program to print even and odd by two threads

using namespace std;
class Test {
	thread m_threadOdd, m_threadEven;
	mutex m_mutex;
	condition_variable_any m_cv;
	bool m_oddDone;
	bool m_evenDone;
public:
	Test() {
		m_oddDone = false;
		m_evenDone = true;
		m_threadOdd = thread(&Test::printOdd, this);
		m_threadEven = thread(&Test::printEven, this);
		m_threadOdd.join();
		m_threadEven.join();
	}
	void printOdd() {
		int i = 1;
		while (i <= 30) {
			m_mutex.lock();
			m_cv.wait(m_mutex, [this]{return this->m_oddDone; });
			cout << "From ODD thread "<< i << endl;
			m_mutex.unlock();
			m_oddDone = true;
			m_oddDone = false;
			i = i + 2;
			m_cv.notify_all();
		}
	}
	void printEven(){
		int i = 2;
		while (i <= 30) {
			m_mutex.lock();
			m_cv.wait(m_mutex, [this]{return this->m_oddDone; });
			cout <<"From EVEN thread " <<i << endl;
			m_mutex.unlock();
			m_oddDone = true;
			m_oddDone = false;
			i = i + 2;
			m_cv.notify_all();
		}
	}
	
};
int main() {
	Test t;

	system("pause");
	return 0;

}