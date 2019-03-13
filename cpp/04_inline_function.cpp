#include "stdafx.h"
#include "iostream"

using namespace std;

//内联函数声明时，inline关键字要和函数体的实现写在一起
//否则编译器会直接忽略内联请求
//inline void printA();//只申明，可能会被编译器忽略
inline void printA() {
	int a = 10;
	cout << "a" << a << endl;
}

int main04() {
	//printA();
	//C++ 编译器直接将函数体插入在函数调用的不同地方
	{
		int a = 10;
		cout << "a" << a << endl;
	}

	cout << "hello" << endl;
	system("pause");
	return 0;
}