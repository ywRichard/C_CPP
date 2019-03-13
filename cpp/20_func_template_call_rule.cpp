#include "stdafx.h"
#include <iostream>

using namespace std;

//a.普通函数可以进行自动类型转换
//b.函数模板不允许自动类型转换(类型参数化, 严格按照类型进行匹配; 但允许隐式类型推导)

/*
	1.函数模板可以像普通函数一样被重载
	2.c++编译器优先考虑普通函数
	3.如果函数模板可以产生一个更好的匹配,那么选择模板
	4.可以通过 “空模板实参列表” 限定编译器只通过模板匹配
*/

int Max(int a, int b) {
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b) {
	cout << "T Max(T a, T b) " << endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b, T c) {
	cout << "T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b), c);
}

int main() {
	int a = 1;
	int b = 2;
	
	cout << Max(a, b) << endl;//2->当函数模板和普通函数都符合调用时, 普通函数优先
	cout << Max<>(a, b) << endl;//4->通过“空模板实参列表”限定编译器只通过模板匹配

	cout << Max(3.0, 4.0) << endl;//3->如果函数模板可以产生一个更好的匹配, 选择模板
	
	cout << Max(5.0, 6.0, 7.0) << endl;//1->模板函数重载
	cout << Max('a', 100) << endl;//调用普通函数, 进行隐式类型转换。由于类型不一致, 不能调用函数模板。

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
