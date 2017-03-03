#include <iostream>

using namespace std;

struct LL {
	int data;
	LL* nxt;
};

class LinkedList {
	LL* l;
	

public:
	LinkedList() {
		l = NULL;
	}
	void createLinkedList(int x) {
		LL* tmp = new LL;
		tmp->data = x;
		tmp->nxt = NULL;
		if (l == NULL){
			l = tmp;
			return;
		}

		LL* tt = new LL;
		tt = l;
		while (tt->nxt) {
		  tt = tt->nxt;
		}
		tt->nxt = tmp;
		return;
	}

	void print() {
		if (l == NULL) {
			return;
		}
		LL* tmp = l;
		while (tmp) {
			cout << "Data: " << tmp->data << " " ;
			tmp = tmp->nxt;
		}
		return;
	}

	void revseserLinkedList() {
		if (l == NULL) {
			return;
		}
		LL* prev, *curr, *next;
		prev = NULL;
		curr = l;
		next = l->nxt;

		while (curr)
		{
			next = curr->nxt;
			curr->nxt = prev;
			prev = curr;
			curr = next;
		}
		l = prev;
	
	}
};

int main() {
	LinkedList* list = new LinkedList();
	list->createLinkedList(10);
	list->createLinkedList(20);
	list->createLinkedList(30);
	list->createLinkedList(40);
	list->createLinkedList(50);

	list->print();
	cout << "\n----\n" << endl;
	list->revseserLinkedList();
	cout << "----" << endl;
	list->print();
	
	system("pause");
	return 0;

}

