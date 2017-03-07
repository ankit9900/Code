#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <iostream>
using namespace std;
class ISubject;

class IObserver {
public:
	virtual void update(string) = 0;
	virtual void subscribeMe() = 0;
	virtual void unsubscribeMe() = 0;
	virtual void print() = 0;
};

#endif
