#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	int a;
};

class B1 : virtual public A {
public:
	int b1;
};

class B2 : virtual public A {
public:
	int b2;
};

class C : public B1, public B2 {
public:
	int c;
};

int main162() {
	C c1;
	c1.a = 123;//if not mark as virtual, there is ambiguous error
	//c1.b1 = 100;
	//c1.b2 = 100;
	//c1.c = 20;

	cout << "sizeof(A):" << sizeof(A) << endl;//4
	cout << "sizeof(B1):" << sizeof(B1) << endl;//12, virtual cost 4bytes
	cout << "sizeof(B2):" << sizeof(B2) << endl;//8
	cout << "sizeof(C):" << sizeof(C) << endl;//24

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
