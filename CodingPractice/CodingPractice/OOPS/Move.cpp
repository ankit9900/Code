#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class MemoryMgm {
	size_t size;
	char* buf;
public:
	explicit MemoryMgm(int sz = 512) :size(sz), buf(new char[size]) {

	}
	~MemoryMgm() {
		cout << "\n DTR \n" << endl;
		delete[] buf;
	}
	MemoryMgm(const MemoryMgm& src){
		cout << "COPY CTR" << endl;
		size = src.size;
		buf = new char[size];
		strcpy(buf, src.buf);
	}
	const MemoryMgm& operator= (const MemoryMgm& src) {
		if (this == &src){
			return *this;
		}
		if (buf){
			delete []buf;
		}
		
		size = src.size;
		buf = new char[src.size];
		strcpy(buf, src.buf);
		return *this;
	}
	// Move ctr 
	
	MemoryMgm(MemoryMgm&& src):size(0),buf(nullptr) {
		cout << "MOVE CTR" << endl;
		size = src.size;
		buf = src.buf;
		src.size = 0;
		src.buf = nullptr;
	}
	//Move Assignment operator
	MemoryMgm& operator= (MemoryMgm&& src) {
		if (this != &src) {
			delete[] buf;
			size = 0;

			size = src.size;
			buf = src.buf;

			src.size = 0;
			src.buf = nullptr;
		}
		return *this;
	}

	void test() {
		cout << size << endl;
	}
};

int main() {
	MemoryMgm m1(1024); // lvalue
	vector<MemoryMgm> vmgm;
	vmgm.push_back(m1);

	cout << "\n--------\n" << endl;
	
	MemoryMgm m2(1045); 
	vmgm.push_back(static_cast<MemoryMgm&&>(m2));  // Force Move
	cout << "\n--------\n" << endl;

	cout << "\n--------\n" << endl;
	MemoryMgm m3(1045);
	vmgm.push_back(move(m3));  // Force Move
	cout << "\n--------\n" << endl;
	
	vmgm.push_back(MemoryMgm(2024));
	cout << "\n--------\n" << endl;
	

	MemoryMgm m5(1022);

	MemoryMgm m6 = move(m5);
	m6.test();
	m5.test();
	system("pause");
	return 0;
}