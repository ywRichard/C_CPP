#include "stdafx.h"
#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a = 0) {
		this->_a = a;
	}

	virtual void print() {
		cout << "Parent's print():" << _a << endl;
	}
private:
	int _a;
};

//一次偶然的成功比必然的失败更可怕
class Child : public Parent {
public:
	Child(int a = 0, int b = 0) : Parent(a) {
		this->_b = b;
	}
	virtual void print() {
		cout << "Child's print():" << _b << endl;
	}
private:
	int _b;
};

int main() {

	Parent *pP = NULL;
	Parent *pC = NULL;

	Child c[] = { Child(1),Child(2),Child(3) };
	pP = c;
	pC = c;
	pP->print();//多态发生
	pC->print();

	//结论：多态是用父类指针指向子类对象 和 父类步长++, 是两个不同的概念。
	//父类和子类的数据结构不同, 分配的内存空间也不一样。所以指针寻址的步长也不相同
	pP++;
	pC++;
	pP->print();//core down
	pC->print();

	pP++;
	pC++;
	pP->print();
	pC->print();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
