#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <iostream>
#include <vector>
#include "IObserver.h"
using namespace std;

class IObserver;
class ISubject {
	vector<IObserver*> m_vecObservers;
public:
	void subscribe(IObserver*);
	void unsuscribe(IObserver*);
	void notify();
};

#endif