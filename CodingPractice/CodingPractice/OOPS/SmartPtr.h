#include <iostream>
// Templated smart pointer .. Njoy
using namespace std;

class Ref {
	int count;
public:
	Ref() {
		count = 0;
	}
	void inc() {
		count++ ;
	}

	void deref() {
		count--;
	}

	int getRef() {
		return count;
	}
};

template < typename T>
class container {
	T* raw;
public:
	container() {
		raw = nullptr;
	}

	container(T tmp) {
		this->raw = new T;
		*raw = tmp;
	}

	container(const T& tmp, int x = 0) {
		this->raw = new T;
		*raw = tmp;
	}
    
	container(const container& tmp) {
		this->raw = tmp.raw;
	}
	
	container& operator=(const container& tmp) {
		if (this != &tmp) {
			this->raw = new T;
			*this->raw = *(tmp.raw);
		}
		return *this;
	}
	~container()  {
		delete raw;
	}
	T* returnPtr() {
		return raw;
	}
	T& returnRef() {
		return *raw;
	}
};

template < class T>
class SmartPtr {
	container<T>* p;
	Ref* r;
public:
	~SmartPtr() {
		r->deref();
		if (r->getRef() == 0){
			delete p;
			delete r;
		}
	}
	SmartPtr():p(nullptr),r(nullptr) {
	
	}

	SmartPtr(T tmp):r(nullptr) {
		p = new container<T>(tmp);
		r->inc();
	}

	SmartPtr(T* tmp1) {
		p = new container<T>(*tmp1,0);
		r = new Ref();
		r->inc();
	}
	// Copy Ctr with non const param
	SmartPtr(SmartPtr& tmp) {
		p = tmp.p;
		r = tmp.r;
		tmp.r->inc();
	}

	SmartPtr& operator=(SmartPtr& tmp) {
		p = tmp.p;
		r = tmp.r;
		tmp.r->inc();
		return *this;
	}

	T* operator->(){
		return p->returnPtr();
	}

	T& operator*(){
		return p->returnRef();
	}
};
