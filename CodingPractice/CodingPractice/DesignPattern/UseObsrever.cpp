#include "IObserver.h"
#include "ISubject.h"
#include "Observer.h"
#include "Observer2.h"

int main() {
	ISubject* subject = new ISubject;
	IObserver* observer1 = new Observer(subject,"ob1");
	IObserver* observer2 = new Observer2(subject,"ob2");
	
	observer1->subscribeMe();
	observer2->subscribeMe();

	observer1->print();
	observer2->print();

	subject->notify();

	observer1->print();
	observer2->print();
	
	cout << "OB2 UnsubscribeMe ---" << endl;
	observer2->unsubscribeMe();

	subject->notify();

	observer1->print();
	observer2->print();


	system("pause");
	return 0;


}