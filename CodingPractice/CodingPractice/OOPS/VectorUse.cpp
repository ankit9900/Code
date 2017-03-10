#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <string>
using namespace std;

class Temp {
	char* m_ptr;
public:
	Temp(char* p = nullptr):m_ptr(p == nullptr ? nullptr:new char[strlen(p) + 1]) {
		strcpy(m_ptr, p);
		cout << "CTR TEMP " << endl;
	}
	~Temp() {
		delete[] m_ptr;
	}
	Temp(const Temp& right) {
		m_ptr = new char[strlen(right.m_ptr) + 1];
		strcpy(m_ptr, right.m_ptr);
	}

	Temp& operator=(const Temp& right) {
		if (this != &right) {
			m_ptr = new char[strlen(right.m_ptr) + 1];
			strcpy(m_ptr, right.m_ptr);
		}
		return *this;
	}
	void print() {
		cout << m_ptr << endl;
	}
	char* getChar() {
		return m_ptr;
	}
};
class Widget {
	int m_type;
	string m_name;
	Temp* m_temp;
public:
	Widget(int type = 0, string name = "default", Temp* p= nullptr) : m_type(type), m_name(name),m_temp(p == nullptr?nullptr:p) {
		cout << "CTR " << endl;
		
	}
	~Widget() {
		delete m_temp;
		cout << "DTR " << endl;
	}

	Widget(const Widget& other) {
		cout << "CCC" << endl;
		m_type = other.m_type;
		m_name = other.m_name;
		m_temp = new Temp(other.m_temp->getChar());

	}

	Widget(Widget&& other):m_type(other.m_type),m_name(move(other.m_name)),m_temp(other.m_temp) {
		cout << "MMM" << endl;
		other.m_temp = nullptr;
	}

	Widget& operator=(Widget other){
		if (this != &other) {
			m_type = other.m_type;
			m_name = move(other.m_name);
			m_temp = (other.m_temp);
			other.m_temp = nullptr;
		}
		return *this;
	}

	Widget fun() {
		this->m_name = "king";
		Widget w;
		w.m_name = this->m_name;
		w.m_type = 200;
		w.m_temp = new Temp (m_temp->getChar());
		return w;
	}
	void print() {
		cout << "\n---m_name: " << m_name << " --type: " << m_type << endl;
		m_temp->print();
	}
};

int main() {
	Temp* t = new Temp("ankit");
	Widget w(10, "ankit",t);
	Widget w1(w.fun());
	w1.print();
	system("pause");
	return 0;
}