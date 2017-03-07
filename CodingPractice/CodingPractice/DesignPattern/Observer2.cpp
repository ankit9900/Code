#include "Observer2.h"
#include <string>

Observer2::Observer2(ISubject* sub, string _name) {
	m_subject = sub;
	m_name = _name;
}

void Observer2::update(string msg)  {
	cout << "Obsrver updated " << endl;
	m_name = m_name + "Modified 222" + msg;
}

void Observer2::subscribeMe() {
	m_subject->subscribe(this);
}

void Observer2::unsubscribeMe() {
	m_subject->unsuscribe(this);
}

void Observer2::print() {
	cout << m_name << endl;
}

