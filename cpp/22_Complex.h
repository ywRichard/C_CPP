#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename T>
class Complex {
	//friend Complex& MySub<T>(Complex &c1, Complex &c2);
	friend void print(Complex &c);
	friend ostream& operator<< <T>(ostream &out, Complex &c);
	
public:
	Complex(T a, T b);
	void printCom();
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);

	//friend ostream& operator<< <T>(ostream &out, Complex &c);
private:
	T a;
	T b;
};
