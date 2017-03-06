#include <iostream>
#include <stdlib.h>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;


class ProCon {
	int* m_buffer;
	int m_len;
	bool m_full;
	bool m_empty;
	int m_currentIndex;
	thread m_producer;
	thread m_consumer;
	mutex m_mutex;
	condition_variable_any m_cv;
public:
	ProCon() {

	}

	~ProCon() {
		delete[] m_buffer;
	}

	long int gen() {
		return rand() % 100 + 1;
	}

	ProCon(int _x): m_len(_x), m_buffer(new int[_x]),m_full(false),m_empty(true),m_currentIndex(0){
		m_producer = thread(&ProCon::producer, this);
		m_consumer = thread(&ProCon::consumer, this);
		
		m_consumer.join();
		m_producer.join();
	}

	bool checkOverFlow() {
		if (m_currentIndex == m_len){
			return true;
		}
		return false;
	}

	bool checkUnderFlow() {
		if (m_currentIndex < 0) {
			return true;
		}
		return false;
	}

	void producer() {
		while (1) {
			m_mutex.lock();

			m_cv.wait(m_mutex, [this]{return this->m_empty && !this->checkOverFlow() ;});
			m_buffer[m_currentIndex++] = gen();
			cout << "Generated " << endl;
			m_full = true;
			m_empty = false;
			
			m_mutex.unlock();
			m_cv.notify_all();
		}
	}

	void consumer() {
		while (1) {
			m_mutex.lock();

			m_cv.wait(m_mutex, [this]{return this->m_full && !this->checkUnderFlow(); });
			int val = m_buffer[--m_currentIndex];
			cout << " Val  " << val << endl;
			m_empty = true;
			m_full = false;

			m_mutex.unlock();
			m_cv.notify_all();
		}
	}
};
int main() {
	ProCon obj(10);

	system("pause");
	return 0;

}