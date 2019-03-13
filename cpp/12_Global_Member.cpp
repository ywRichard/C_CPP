#include "stdafx.h"
#include "iostream"

using namespace std;

class Test {
public:
	int _a;
	int _b;
public:
	Test(int a = 0, int b = 0) {
		this->_a = 0;
		this->_b = 0;
	}
	~Test() {
		cout << "_a:" << _a << "_b:" << _b << endl;
		cout << "析构函数自动被调用" << endl;
	}
	void printT() {
		cout << "_a:" << _a << "_b:" << _b << endl;
	}
	Test TestAdd(Test &t2) {
		Test tmp(this->_a + t2._a, this->_b + t2._b);
		return tmp;
	}

	//返回一个引用 相当于返回自身
	//返回t1这个元素 this就是&t1
	Test TestAdd2(Test &t2) {
		this->_a = this->_a + t2._a;
		this->_b = this->_b + t2._b;

		return *this;//把 *(&t1) 又回到t1元素
	}
private:
};

//全局函数的方法
//全局函数传换成成员函数，要少一个参数
Test TestAdd(Test &t1, Test &t2) {
	Test tmp(t1._a + t2._a, t1._b + t2._b);
	return tmp;
}

int main12() {
	Test t1(1, 2);
	Test t2(3, 4);

	Test t3;
	//全局函数方法
	t3 = TestAdd(t1, t2);

	//成员函数方法
	{
		//先把测试案例写出来
		Test t4 = t1.TestAdd(t2);//匿名对象直接转化成t4
		t4.printT();
		Test t5;
		t5 = t1.TestAdd(t2);//匿名对象 复制 给t5
		t5.printT();
	}

	t1.TestAdd2(t2);
	t1.printT();

	cout << "hell0..." << endl;
	system("pause");
	return 0;
}