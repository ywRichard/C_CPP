#include "stdafx.h"
#include <iostream>

using namespace std;

class Test3 {
public:
	Test3(int a, int b) {
		this->a = a;
		this->b = b;
		printf("Test3(a:%d,b:%d)\n", this->a, this->b);
	}
	~Test3() {
		printf("~Test3(a:%d,b:%d)\n", this->a, this->b);
	}
private:
	int a;
	int b;
};
void myDivide() {
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivide... throw exception." << endl;
	throw 1;
}
int main() {

	try {
		myDivide();
	}
	catch (int i) {
		cout << "catch int exception" << endl;
	}
	catch (...) {
		cout << "unknown exception" << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}