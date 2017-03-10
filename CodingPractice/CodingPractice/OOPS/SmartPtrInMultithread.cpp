#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
mutex m;
condition_variable_any cv;
bool first = true;
bool second = false;

bool first1 = true;
bool second1 = false;

class Widget {
	int m_type;
	string m_name;
public:
	void modify() {
		m_type = 200;
		m_name = "oracle";
	}
	Widget(int _x = 1, string _name="BoxD") :m_type(_x), m_name(_name) {
		cout << "Ctr Widget " << endl;
	}
	//Widget() {};

	~Widget() {
		cout << "Dtr Widget" << endl;
	}

	Widget(const Widget& other) {
		m_type = other.m_type;
		m_name = other.m_name;
	}

	Widget& operator=(const Widget& other){
		if (this != &other){
			m_type = other.m_type;
			m_name = other.m_name;
		}
		return *this;
	}
	void print() {
		cout << "\n m_name " << m_type << " Name " << m_name << endl;
	}
	
};
void func(shared_ptr<Widget>& ss) {
	m.lock();
	cv.wait(m, []{return first; });
	cout << "\n---func use_count = "<< ss.use_count() << endl;
	cout << ss.get();
	delete ss.get();
	ss->print();
	ss->modify();
	ss = nullptr;
	first = false;
	second = true;
	ss = nullptr;
	cout << "\n---func use_count END = " << ss.use_count() << endl;
	m.unlock();
	cv.notify_all();
	//cout << "func use_count" << ss.use_count() << endl;
}

void func1(Widget* ss) {
	ss->print();
}

void func2(shared_ptr<Widget>& ss) {
	m.lock();
	cv.wait(m, []{return second;});
	cout << "\n--func2 use_count = " << ss.use_count()<<endl;
	cout << ss.get();
	ss->print();
	ss = nullptr;
	first = true;
	second = false;
	ss = nullptr;
	cout << "\n---func2 use_count END = " << ss.use_count() << endl;
	m.unlock();
	cv.notify_all();
	//cout << "func2 use_count" << ss.use_count() << endl;
}
void func3(shared_ptr<Widget>& ss) {
	m.lock();
	cv.wait(m, []{return second1; });
	cout << "\n--func3 use_count = " << ss.use_count() << endl;
	cout << ss.get();
	ss->print();
	ss = nullptr;
	first1 = true;
	second1 = false;
	ss = nullptr;
	cout << "\n---func3 use_count END = " << ss.use_count() << endl;
	m.unlock();
	cv.notify_all();
	//cout << "func2 use_count" << ss.use_count() << endl;
}
void func4(shared_ptr<Widget>& ss) {
	m.lock();
	cv.wait(m, []{return second1; });
	cout << "\n--func4 use_count = " << ss.use_count() << endl;
	cout << ss.get();
	ss->print();
	ss = nullptr;
	first1 = true;
	second1 = false;
	ss = nullptr;
	cout << "\n---func4 use_count END = " << ss.use_count() << endl;
	m.unlock();
	cv.notify_all();
	//cout << "func2 use_count" << ss.use_count() << endl;
}

int main() {
	Widget* widPtr = new Widget(1, "Box");
	Widget* widPtr2 = new Widget(2, "Box2");

	shared_ptr<Widget> sp1 = make_shared<Widget>(3, "Box3");
	cout << "\n -- Main thread  111 = " << sp1.use_count() << endl;
	thread t1(bind(func, sp1));
	cout << "\n&&&&&&&&&&&&&&&&\n";

	cout << "\n -- Main thread 2222 =  " << sp1.use_count() << endl;
	thread t2(bind(func2,sp1));
	cout << "\n&&&&&&&&&&&&&&&&\n";

	/*cout << "\n --Main thread 333 = " << sp1.use_count() << endl;
	thread t3(func3, sp1);
	cout << "\n&&&&&&&&&&&&&&&&\n";

	cout << "\n --Main thread 444  = " << sp1.use_count() << endl;
	thread t4(func4, sp1);
	cout << "\n&&&&&&&&&&&&&&&&\n";
	*/
	cout << "\n --Main thread 555 = " << sp1.use_count() << endl;
	t1.join();
	t2.join();
	//t3.join();
	//t4.join();
	cout << "Main thread END " << sp1.use_count() << endl;
	system("pause");
	return 0;


}