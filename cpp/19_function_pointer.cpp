#include "stdafx.h"
#include <iostream>

using namespace std;

//数组类型的基本语法知识梳理
int main01() {
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 a+1->4; &a+1->40

	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];//自定义数组
		myTypeArray myArray;
		myArray[0] = 10;
		cout << "myArray[0]: " << myArray[0] << endl;
	}

	{
		//定义一个指针数组类型
		typedef int(*pTypeArray)[10];//int *p

		pTypeArray myPArray;//sizeof(mPArray) *10
		myPArray = &a;
		//int b=10;
		//int *p=NULL;
		//p=&b;
		(*myPArray)[0] = 20;
		cout << "a[0]: " << a[0] << endl;
		cout << "(*myPArray)[0]: " << (*myPArray)[0] << endl;
	}
	{
		//定义一个指向数组类型的指针 数组类的指针
		int(*myPointer)[10];//变量 告诉c编译器 给我分配内存
		myPointer = &a;
		(*myPointer)[0] = 30;
		cout << "(*myPointer)[0]: " << (*myPointer)[0] << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

//函数指针基本语法
//1.如何定义一个 函数类型
//2.如何定义一个 函数指针类型
//3.如何定义一个 函数指针
int add(int a, int b) {
	cout << "func add...: " << a << " + " << b << endl;
	return a + b;
}

int main() {
	add(1, 2);//直接调用, 函数名就是函数的入口地址

	//1.自定义函数类型
	{
		//typedef int(MyFuncType)(int a, int b);
		typedef int(MyFuncType)(int, int);//1.自定义函数数据类型
		MyFuncType *pMyFuncType = NULL;

		pMyFuncType = &add;//取函数的入口地址
		pMyFuncType(3, 4);//call indirectly

		pMyFuncType = add;//兼容c的历史版本
		pMyFuncType(5, 6);
	}

	//2.自定义函数指针类型
	{
		typedef int(*MyPointerFuncType)(int, int);//int *a=NULL;
		MyPointerFuncType myPointerFunc;//定义一个指针
		myPointerFunc = add;
		myPointerFunc(7, 8);
	}

	//3.定义 函数指针 变量
	{
		int(*myFuncPoint)(int, int);//定义一个变量
		myFuncPoint = add;
		myFuncPoint(9, 10);
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

