#include "stdafx.h"
#include <iostream>

using namespace std;

//uncouple (解耦合)
class Figure//abstract
{
public:
	virtual void getArea() = 0;//pure virtual function
};

class Circle :public Figure {
public:
	Circle(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << "the area of circle: " << 3.14*a*a << endl;
	}
private:
	int a;
	int b;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << "the area of triangle: " << a * b / 2 << endl;
	}
private:
	int a;
	int b;
};

class Square :public Figure {
public:
	Square(int a, int b) {
		this->a = a;
		this->b = b;
	}
	virtual void getArea() {
		cout << "the area of square: " << a * b << endl;
	}
private:
	int a;
	int b;
};

void objPlay(Figure *base) {
	base->getArea();//polymorphism
}

int main() {
	Figure *base = NULL;

	Circle c1(10, 20);//抽象类不能被实例化
	Triangle t1(20, 30);
	Square s1(50, 60);

	//面向抽象类编程(面向一套预先定义好的接口编程)
	objPlay(&c1);
	objPlay(&t1);
	objPlay(&s1);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
