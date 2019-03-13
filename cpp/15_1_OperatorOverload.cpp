#include "stdafx.h"
#include <iostream>

using namespace std;

class Complex {
private:
	int _a;
	int _b;
	friend Complex myAdd(Complex &c1, Complex &c2);
public:
	friend Complex operator+(Complex &c1, Complex &c2);
	friend Complex& operator++(Complex &c1);
	friend Complex operator++(Complex&c2, int);
	Complex(int a = 0, int b = 0) {
		this->_a = a;
		this->_b = b;
	}
	void printCom() {
		cout << _a << "+" << _b << "i" << endl;
	}
public:
	//1.binary operator, override by member function
	Complex operator-(Complex &c2) {
		Complex tmp(this->_a - c2._a, this->_b - c2._b);
		return tmp;
	}

	//2.prefix operator --a, member function
	Complex& operator--() {
		--this->_a;
		--this->_b;
		return *this; //dereference this point
	}

	//3.prefix operator --a, member function
	Complex operator--(int) {
		Complex tmp = *this;
		this->_a--;
		this->_b--;
		return tmp;
	}
};

//1.binary operator, override by global function -> friend function
Complex operator+(Complex &c1, Complex &c2) {
	Complex tmp(c1._a + c2._a, c1._b + c2._b);
	return tmp;
}

//2.prefix operator ++a, by global
Complex& operator++(Complex &c1) {
	++c1._a;
	++c1._b;
	return c1;
}

//3.postfix operator a++, by global
Complex operator++(Complex&c2, int) {
	Complex tmp = c2;//postfix operator, set the value after used
	c2._a++;
	c2._b++;
	return tmp;
}

/*
1.operator override is implemented by function.
2.function parameters
3.return value(reference, point, element)
*/
int main151() {
	Complex c1(1, 2), c2(3, 4);
	//1.binary operator, global function
	//Complex operator+(Complex &c1, Complex &c2)
	Complex c3 = c1 + c2;
	c3.printCom();

	//1.binary operator, member function
	//c1.operator-(c2);
	//Complex operator-(Complex &c2)
	Complex c4 = c1 - c2;
	c4.printCom();

	//2.unary prefix operator(++a), by global function
	++c1;
	c1.printCom();
	//2.prefix operator (--a) by member function
	--c1;
	c1.printCom();

	//3.postfix operator(a++), by global
	c2++;
	c2.printCom();

	//3.postfix operator(a--), by member
	c2--;
	c2.printCom();


	cout << "hello..." << endl;
	system("pause");
	return 0;
}


//#################################################
//1. global add function
Complex myAdd(Complex &c1, Complex &c2) {
	Complex tmp(c1._a + c2._a, c1._b + c2._b);
	return tmp;
}

//Complex operator+(Complex &c1, Complex &c2) {
//	Complex tmp(c1._a + c2._a, c1._b + c2._b);
//	return tmp;
//}

int main152() {
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