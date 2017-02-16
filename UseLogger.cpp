#include "logger.h"

class TestLogger {
	
	int x;
public:
	TestLogger() {
		x = 3;
		logger::INFO("Created TestLogger");
	}
	~TestLogger() {
		logger::INFO("Deleted TestLogger");
	}
	void test(int k) {
		x = 10;
		
		logger::INFO("called test()");
	}

};

int main() {
	TestLogger t;
	t.test(10);
	system("pause");
	return 0;
}