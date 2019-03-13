#include "stdafx.h"
#include <iostream>

using namespace std;

class Parent {
public:
	void printP() {
		cout << "I'm father..." << endl;
	}
private:
	int a;
};

class Child :public Parent {
public:
	void printC() {
		cout << "I'm son..." << endl;
	}
private:
	int c;
};

/*类型兼容规则
1.子类对象可以当作父类对象使用
2.子类对象可以直接赋值给父类对象
3.子类对象可以直接初始化父类对象
4.父类指针可以直接指向子类对象
5.父类引用可以直接引用子类对象
*/

void HowToPrint(Parent *base) {
	base->printP();
}

void HowToPrint2(Parent &base) {
	base.printP();
}

int main161() {
	Parent p1;
	p1.printP();

	Child c1;
	c1.printC();
	c1.printP();

	//赋值兼容性原则
	//1-1.基类指针(引用)指向子类对象
	Parent *p = NULL;
	p = &c1;
	p->printP();

	//1-2.指针做函数参数
	HowToPrint(&p1);
	HowToPrint(&c1);
	//1-3.引用做函数参数
	HowToPrint2(p1);
	HowToPrint2(c1);

	//第二层含义
	//可以让 父类对象 初始化 子类对象
	//子类是一种特殊的父类
	Parent p3 = c1;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
