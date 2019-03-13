#include "stdafx.h"
#include "iostream"

using namespace std;

int main02() {
	const int a = 10;
	int *p = NULL;
	p = (int *)&a;
	*p = 20;
	cout << "a:" << a << endl;
	cout << "*p:" << *p << endl;
	cout << "&a:" << &a << endl;
	cout << "p:" << p << endl;
	system("pause");

	return 0;
}