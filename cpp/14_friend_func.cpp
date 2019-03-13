#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	//The usage synario of friend function is "operator override"
	//1.声明的位置和public, private没有关系
	//2.函数modifyA是类的好朋友
	friend void modifyA(A *pA, int _a);
	A(int a, int b) {
		this->a = a;
		this->b = b;
	}
	int getA() {
		return this->a;
	}

private:
	int a;
	int b;
};

void modifyA(A *pA, int a) {
	pA->a = a;
}

int main141() {
	A a1(1, 2);
	cout << a1.getA() << endl;
	modifyA(&a1, 300);
	cout << a1.getA() << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
