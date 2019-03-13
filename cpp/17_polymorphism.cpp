#include "stdafx.h"
#include <iostream>

using namespace std;
class Parent
{
public:
	Parent(int a) {
		this->_a = a;
		cout << "Parent a:" << _a << endl;
	}

	//实现多态才是 virtual函数 真正的应用场景
	//不写virtual, 静态联编, C++编译器根据声明的类型去调用函数, -> 编译阶段 (因为在编译阶段，编译器还不知道函数实际加载的参数类型是什么)
	//写virtural, 动态联编, 编译器会延迟绑定, 在运行时根据加载的类型去调用相应的函数, -> 运行时
	virtual void print() { //1.写virtual会特殊处理, 虚函数表
		cout << "Parent's print():" << _a << endl;
	}
private:
	int _a;
};

class Parent2
{
public:
	Parent2(int a) {
		this->_a = a;
		cout << "Parent a:" << _a << endl;
	}

	void print() { //不加virtual关键字, 证明vptr的存在
		cout << "Parent's print():" << _a << endl;
	}
private:
	int _a;
};


class Child : public Parent {
public:
	Child(int b): Parent(10) {
		this->_b = b;
		cout << "Child b:" << _b << endl;
	}
	virtual void print() { //子类的virtual并不是必须要加的，但是加上跟明确
		cout << "Child's print():" << _b << endl;
	}
private:
	int _b;
};

void HowToPrint(Parent *base) {
	//2.有多态发生
	//效果: 根据传来的类执行不同的print函数实现。C++编译器根本不需要区分是子类对象还是父类对象,
	//子类对象和父类对象分别有vptr指针==>虚函数表==>函数的入口地址
	//延迟绑定 ---> 运行时的时候, c++编译器才判断
	base->print();//一条语句，有多种表现形态-->polymorphism
}

void HowToPrint2(Parent &base) {
	base.print();
}

int main() {
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);

	//point
	base = &p1;
	base->print();

	base = &c1;
	base->print();

	//reference
	Parent &base2 = p1;
	base2.print();
	Parent &base3 = c1;
	base3.print();

	//function call
	HowToPrint(&p1);
	HowToPrint(&c1);

	HowToPrint2(p1);
	HowToPrint2(c1);

	cout << "sizeof(Parent):" << sizeof(Parent) << " sizeof(Parent2):" << sizeof(Parent2) << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
