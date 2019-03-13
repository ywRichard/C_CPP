#include "stdafx.h"
#include <iostream>

using namespace std;

class Complex
{
public:
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}

	void printCom() {
		cout << a << " + " << b << "i" << endl;
	}
};

//1. global add function
Complex myAdd(Complex &c1, Complex &c2) {
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

Complex operator+(Complex &c1, Complex &c2) {
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

int main151() {
	int a = 0, b = 0;
	int c;
	//1.for base data type, compiler knows how to operator.
	c = a + b;

	//a+bi, complex operation run
	Complex c1(1, 2), c2(3, 4);
	Complex c3;
	//2.class is a kind of customzied data type, compiler didn't implement it by default
	//c3=c1+c2

	//3.cpp compiler provides a mechanism to implement 
	//a customized opreation for customized datatype ===> operator override

	//4.operator override
	//step1
	//c3 = myAdd(c1, c2);

	//step2
	c3 = operator+(c1, c2);

	//step3
	//c3 = c1 + c2;
	c3.printCom();

	//conclusion, operator is a function

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
