#include "stdafx.h"
#include <iostream>

using namespace std;

class Test {
	int i;
public:
	Test(int i) {
		this->i = i;
	}

	Test operator+(const Test &obj) {
		Test ret(0);
		cout << "执行 + 号重载函数" << endl;
		ret.i = i + obj.i;
		return ret;
	}

	bool operator&&(const Test &obj) {
		cout << "执行&&重载函数" << endl;
		return i && obj.i;
	}
};

int main() {
	int a1 = 0;
	int a2 = 1;
	cout << "Notes, && count from left to right" << endl;
	if (a1 && (a1 + a2))
	{
		cout << "有一个是假，则不执行下一个表达式的计算" << endl;
	}

	Test t1 = 0;
	Test t2 = 1;
	if (t1 && (t1 + t2))
	{
		//t1.operatpr&&(t1.operator+(t2))
		cout << "两个函数都被执行了，而且是先执行了+" << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
