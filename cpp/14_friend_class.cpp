#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	friend class B;//B类是A的好朋友，在B中可以访问A类的私有成员和私有函数

	friend void modifyA1(A *pA, int _a);
	A(int a = 0, int b = 0) {
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

class B {
public:
	void Set(int a) {
		Aobj.a = a;
	}
	void printB() {
		cout << Aobj.a << endl;
	}
private:
	A Aobj;
};

void modifyA1(A *pA, int a) {
	pA->a = a;
}

int main142() {
	B b1;
	b1.Set(300);
	b1.printB();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
