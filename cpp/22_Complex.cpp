#include "stdafx.h"
#include <iostream>
#include "22_Complex.h"

using namespace std;

template<typename T>
Complex<T>::Complex(T a, T b) {
	this->a = a;
	this->b = b;
}

template<typename T>
void Complex<T>::printCom() {
	cout << "a: " << a << "b: " << b << endl;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c) {
	Complex tmp(this->a + c.a, this->b + c.b);
	return tmp;
}

template<typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c) {
	Complex tmp(this->a - c.a, this->b - c.b);
	return tmp;
}

template<typename T>
ostream& operator<<(ostream &out, Complex<T> &c) {
	out << c.a << " + " << c.b << "i" << endl;
	return out;
}
