#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
using namespace std;

class Test {
	char* str;
public:
	Test(const char* s = nullptr)  {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	Test() :str(nullptr){

	}
	~Test() {
		cout << "Test delete " << str << endl;
		delete[] str;
	}
	char* getStr() {
		return str;
	}

};

class TestErase {
	Test* t;
public:
	TestErase():t(nullptr) {

	}
	TestErase(const char* s = nullptr): t(new Test(s)) {
		
	}
	~TestErase() {
		cout << "TestErase delete " << t << endl;
		delete t;
	}
	char* getStr() {
		return t->getStr();
	}
};

int main() {
	{
		vector<TestErase*> vte;
		vte.push_back(new TestErase("OBJ1"));
		vte.push_back(new TestErase("OBJ2"));
		vte.push_back(new TestErase("OBJ3"));
		vte.push_back(new TestErase("OBJ4"));
		vte.push_back(new TestErase("OBJ5"));
		vte.push_back(new TestErase("OBJ6"));

		int i = 0;
		for (; i < vte.size(); ++i){
			if (strcmp(vte[i]->getStr(), "OBJ4") == 0){
				break;
			}
		}
		if (i < vte.size()){
			delete vte[i];
			vte.erase(vte.begin() + i);
		}
		vte.clear();
	}
	system("pause");
	return 0;

}