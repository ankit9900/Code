#include <iostream>
// Templated smart pointer .. Njoy
using namespace std;

template < typename T>
class Ref {
	int count;
	T* p;
public:
	Ref() {
		count = 0;
	}

	~Ref() {
		deref();
	}

	Ref(T* obj) {
		p = new T;
		*p = *obj;
		ref();
	}
	Ref(T obj) {
		p = new T;
		*p = obj;
		ref();
	}

	void ref() {
		count++;
	}

	void deref() {
		count--;
		if (count == 0){
			delete p;
		}
	}

	T* returnPtr() {
		return p;
	}

	T& returnRef() {
		return *p;
	}

	int getRef() {
		return count;
	}

	T* getRaw() {
		return p;
	}
	
};

template < class T>
class SmartPtr {
	Ref<T>* r;
public:
	~SmartPtr() {
		r->deref();
	}
	SmartPtr(){
		r = new Ref<T>();
	}

	SmartPtr(T tmp) {
		r = new Ref<T>(&tmp);
	}

	SmartPtr(T* tmp1) {
		r = new Ref<T>(tmp1);
	}
	
	SmartPtr(const SmartPtr& tmp) {
		r = tmp.r;
		r->ref();
	}

	SmartPtr& operator=(const SmartPtr& tmp) {
		r->deref();
		r = tmp.r;
		return *this;
	}

	T* operator->() {
		return r->returnPtr();
	}

	T& operator*(){
		return r->returnRef();
	}
	T* getRaw() {
		return r->getRaw();
	}
	int getRefCount() {
		return r->getRef();
	}
	void reset(){
		r->deref();
	}
};
