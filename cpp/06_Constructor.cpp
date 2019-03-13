#include "stdafx.h"
#include "iostream"
using namespace std;

class MyConstructor {
public:
	// no para
	MyConstructor() {
		_a = 0;
		_b = 0;
		cout << "no para constructor" << endl;
	}

	// with para
	MyConstructor(int a, int b) {
		_a = a;
		_b = b;
		cout << "constructor with para" << endl;
	}
	MyConstructor(int num) {
		_a = num;
		_b = _a + num;
		cout << "constructor with para" << endl;
	}

	//copy
	MyConstructor(const MyConstructor &obj) {
		_a = obj._a;
		_b = obj._b;
		cout << "copy constructor" << endl;
	}

	void printObj(char* str) {
		cout << str << " a:" << _a << " b:" << _b << endl;
	}

protected:
private:
	int _a;
	int _b;
};

int main062() {
	{
		//1.无参构造函数，直接调用
		MyConstructor myCons1;
		myCons1.printObj((char*)"myCons1");

		//2.有参构造函数三种调用方法
		MyConstructor myCons2 = 1;//等号调用，适用一个参数?
		myCons2.printObj((char*)"myCons2");

		MyConstructor myCons3(3, 4);//括号调用
		myCons3.printObj((char*)"myCons3");

		MyConstructor myCons4 = MyConstructor(5, 6);//显示调用构造函数
		myCons4.printObj((char *)"myCons4");

		//3.copy constructor

		system("pause");
		return 0;
	}
}