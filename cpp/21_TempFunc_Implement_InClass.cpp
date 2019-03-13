#include "stdafx.h"
#include <iostream>

using namespace std;

// 所有类模板函数在类内部实现
template<typename T>
class Complex {
	friend ostream& operator<<(ostream &out, Complex &c) {
		out << c.a << " + " << c.b << "i" << endl;
		return out;
	}
	friend Complex& MySub(Complex &c1, Complex &c2) {
		Complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}
public:
	Complex(T a, T b) {
		this->a = a;
		this->b = b;
	}
public:
	void printCom(Complex &c2) {
		cout << "a: " << a << "b: " << b << endl;
	}
	Complex& operator+(Complex &c) {
		Complex tmp(c.a + this->a, c.b + this->b);
		return tmp;
	}
private:
	T a;
	T b;
};

int main() {
	//把模板类具体化，分配内存
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	cout << c3 << endl;

	//函数重载 -> 除了重载<< >>只能用友元函数，其他的一律用成员函数。避免友元函数的滥用
	//滥用友元函数
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
