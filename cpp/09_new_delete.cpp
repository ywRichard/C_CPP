#include "stdafx.h"
#include "iostream"

using namespace std;

//1.malloc	free		c 的函数
//	new		delete		c++ 的关键字

//2.new在堆上分配内存 delete
//分配基础类型，分配数组类型，分配对象

//3.new 和 malloc 深入分析
//malloc 不会调用类的构造函数; free 不会调用类的析构函数

class Test {
public:
	Test(int a) {
		_a = a;
		cout << "构造函数" << endl;
	}
	~Test() {
		cout << "析构函数" << endl;
	}
private:
	int _a;
};

void main09() {
	//分配基础类型
	{
		//互换测试delete和free，不会报错
		//c
		int *p = (int *)malloc(sizeof(int));
		*p = 10;
		free(p);
		//delete(p);

		//c++
		int *p2 = new int;//分配基础类型
		*p2 = 20;
		delete p2;
		//free(p2);

		int *p3 = new int(30);
		printf("*p3:%d\n", *p3);
		delete p3;
		//free(p3);
	}

	//分配数组变量
	{
		//互换测试delete和free，不会报错
		//c语言
		int *p = (int*)malloc(sizeof(int) * 10);//int array[10]
		p[0] = 1;
		free(p);

		//c++
		int *pArray = new int[10];
		pArray[1] = 2;
		delete[] pArray;

		char *pArray2 = new char[25];
		delete[] pArray2;
	}

	//分配对象
	{
		//new delete会执行构造函数和析构函数
		//malloc() free()不会

		//c
		Test *pT1 = (Test *)malloc(sizeof(Test));
		free(pT1);
		//delete pT1;

		//c++
		Test *pT2 = new Test(10);
		//delete(pT2);
		free(pT2);
	}
}
