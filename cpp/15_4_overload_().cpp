#include "stdafx.h"
#include <iostream>

using namespace std;

class F {
public:
	int operator()(int a, int b) {
		return a * a + b * b;
	}
	int MemFunc(int a, int b) {
		return a * a + b * b;
	}
};

int main155() {
	F f;
	cout << "Test overload (): " << f(2, 4) << endl;
	cout << "call func : " << f.MemFunc(2, 4) << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
