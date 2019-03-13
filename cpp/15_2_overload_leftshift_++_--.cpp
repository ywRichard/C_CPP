#include "stdafx.h"
#include <iostream>

using namespace std;

class Complex1 {
private:
	int _a;
	int _b;
public:
	Complex1(int a = 0, int b = 0) {
		this->_a = a;
		this->_b = b;
	}
	void printCom() {
		cout << _a << "+" << _b << "i" << endl;
	}
	friend ostream& operator<<(ostream &out, Complex1 &c1);
public:
	//1.binary operator, a+b, a-b
	Complex1 operator-(Complex1 &c2) {
		Complex1 tmp(_a - c2._a, _b - c2._b);
		return tmp;
	}
	Complex1 operator+(Complex1 &c2) {
		Complex1 tmp(_a + c2._a, _b + c2._b);
		return tmp;
	}

	//2.prefix operator --a, ++a
	Complex1& operator--() {
		--this->_a;
		--this->_b;
		return *this; //dereference this point
	}
	Complex1& operator++() {
		++this->_a;
		++this->_b;
		return *this;
	}

	//3.postfix operator, a++, a--
	Complex1 operator--(int) {
		Complex1 tmp = *this;
		this->_a--;
		this->_b--;
		return tmp;
	}
	Complex1 operator++(int) {
		Complex1 tmp = *this;//postfix operator, set the value after used
		_a++;
		_b++;
		return tmp;
	}
};

//void operator<<(ostream & out, Complex1 & c1)
//{
//	cout << "my cout" << endl;
//	cout << c1._a << "+" << c1._b << "i" << endl;
//}

ostream& operator<<(ostream& out, Complex1& c1)
{
	cout << "my cout" << endl;
	cout << c1._a << "+" << c1._b << "i" << endl;
	return out;//为了链式编程，返回一个引用。
}

int main153() {
	int a = 10;
	Complex1 c1(1, 2), c2(3, 4);
	cout << a << endl;

	cout << c1;
	//1.if it's implemented by member function. 
	//ostream类需要添加成员函数，但是ostream是CPP类库，在这种情况下只能用友元函数实现
	//cout.operator<<(, &c1);
	//2.函数返回值当左值，需要返回一个引用
	cout << c1 << "abcd123" << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}


