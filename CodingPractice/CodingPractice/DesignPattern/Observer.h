#ifndef OBSERVER_H
#define OBSERVER_H

#include "IObserver.h"
#include "ISubject.h"
class Observer : public IObserver {
	ISubject* m_subject;
	string m_name;
public:
	Observer() {
	}
	Observer(ISubject*, string);
	virtual void update(string);
	virtual void subscribeMe();
	virtual void unsubscribeMe();
	void print();
};

#endif