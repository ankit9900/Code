#include "Observer.h"
#include <string>

Observer::Observer(ISubject* sub, string _name) {
	m_subject = sub;
	m_name = _name;
}

void Observer::update(string msg) {
	cout << "Obsrver updated " << endl;
	m_name = m_name + "modified" + msg;

}
void Observer::print() {
	cout << m_name << endl;
}
void Observer::subscribeMe() {
	m_subject->subscribe(this);
}

void Observer::unsubscribeMe() {
	m_subject->unsuscribe(this);
}

 