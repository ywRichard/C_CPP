#include "stdafx.h"
#include <iostream>

using namespace std;

/***** 01 syntax of class template ******/
//类模板编程
//类模板 类型参数化
template<typename T>
class A {
public:
	//模板类可以使用默认参数
	A(T a = 0) {
		this->a = a;
	}
	void printA() {
		cout << "a: " << a << endl;
	}
protected:
	T a;
};

//类模板 做函数参数
//参数，c++编译器要具体
void UseA(A<int> &a) {
	a.printA();
}

int main01() {
	//类模板本身就是类型化的-->具体的类-->定义具体变量
	//本质上就是如果不确定参数类型, 编译器就无法分配内存
	A<int> a1(10), a2(20), a3(30);
	a1.printA();

	UseA(a2);
	UseA(a3);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

/***** 02 template class derive common class ******/
//由模板类派生普通类时, 需要具体化模板类的数据类型。
//因为c++编译器需要知道父类的数据类型, 才能为父类分配内存
class B :public A<int> {
public:
	B(int a = 10, int b = 20) :A<int>(a) {
		this->b = b;
	}
	void printB() {
		cout << "a: " << a << " b: " << b << endl;
	}
private:
	int b;
};

int main02() {
	B b1(1, 2);
	b1.printB();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

/***** 03 template class derive template class ******/
//模板类 派生 模板类
template<typename T>
class C :public A<int> {
public:
	C(T a = 10, T c = 20) :A<int>(a) {
		this->c = c;
	}
	void printC() {
		cout << "a: " << this->a << " b: " << this->c << endl;
	}
private:
	T c;
};

int main() {
	C<int> c1(11, 22);
	c1.printC();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
