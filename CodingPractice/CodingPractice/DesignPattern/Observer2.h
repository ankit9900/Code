#ifndef OBSERVER2_H
#define OBSERVER2_H

#include "IObserver.h"
#include "ISubject.h"
class Observer2 : public IObserver {
	ISubject* m_subject;
	string m_name;
public:
	Observer2() {
	}

	Observer2(ISubject*, string);
	virtual void update(string);
	virtual void subscribeMe();
	virtual void unsubscribeMe();
	void print();
};
#endif