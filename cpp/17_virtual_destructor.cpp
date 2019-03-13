#include "stdafx.h"
#include <iostream>

using namespace std;

class A {
public:
	A() {
		_p = new char[20];
		strcpy_s(_p, 20, "obj A");
		printf("A()\n");
	}
	//虚析构函数
	virtual ~A() {
		delete[] _p;
		printf("~A()\n");
	}
private:
	char *_p;
};

class B :public A {
public:
	B() {
		this->_b = new char[20];
		strcpy_s(_b, 20, "obj B");
		printf("B()\n");
	}
	virtual ~B() {
		delete[] _b;
		printf("~B()\n");
	}
private:
	char *_b;
};

class C :public B {
public:
	C() {
		this->_c = new char[20];
		strcpy_s(_c, 20, "obj C");
		printf("C()\n");
	}
	~C() {
		delete[] _c;
		printf("~C()\n");
	}
private:
	char *_c;
};

//只执行了 父类的析构函数
//通过父类指针 把所有的子类对象的析构函数都执行一遍
//通过父类指针 释放所有的子类资源

//如若不用virtual表明虚析构函数, 编译器只会直接调用父类A的析构函数, 而不会按出栈的顺序先析构子类再析构父类
void HowToDelete(A *base) {
	delete[] base;
}

int main() {
	C *my = new C;//new delete 匹配
	//HowToDelete(my);

	delete my;// 按出栈顺序依次调用析构函数, 释放所有资源; 先调用C

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
