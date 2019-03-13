#include "stdafx.h"
#include <iostream>

using namespace std;


// 所有类模板函数在类内部实现
template<typename T>
class Complex {
	friend ostream& operator<< <T>(ostream &out, Complex &c);
	//friend ostream& operator<<(ostream &out, Complex &c);
	
	//友元函数不是类的成员函数, 是全局函数
	friend Complex& MySub(Complex &c1, Complex &c2) {
		Complex tmp(this->a + c.a, this->b + c.b);
		return tmp;
	}
public:
	Complex(T a, T b);
	void printCom();
	Complex operator+(Complex &c);
	Complex operator-(Complex &c);
private:
	T a;
	T b;
};

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

/*
	LNK2019	unresolved external symbol 
	"class std::basic_ostream<char,struct std::char_traits<char> > & 
	__cdecl operator<<
	(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)" 
	(??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)
	模板实现的机制是二次编译。由于友元函数在类中声明和在类外实现, 编译器会生成两个函数头。
	错误的根源，如果按照1的声明, 第一次生成的函数头和第二次生成的不一样。
		1.friend ostream& operator<<(ostream &out, Complex &c);
		2.ostream& operator<<(ostream &out, Complex<T> &c)
*/
template<typename T>
ostream& operator<<(ostream &out, Complex<T> &c) {
	out << c.a << " + " << c.b << "i" << endl;
	return out;
}

int main() {
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	c3.printCom();
	cout << c3 << endl;

	Complex<int> c4 = c1 - c2;
	c4.printCom();
	cout << c4 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
