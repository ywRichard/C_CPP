#include "stdafx.h"
#include "iostream"

using namespace std;

class ABCD {
public:
	ABCD(int a, int b, int c) {
		this->_a = a;
		this->_b = b;
		this->_c = c;
		printf("ABCD() constructor, a:%d, b:%d, c:%d\n", this->_a, this->_b, this->_c);
	}
	ABCD(int a, int b) {
		ABCD(a, b, 100);//会产生一个新的匿名对象
	}
	~ABCD() {
		printf("~ABCD() constructor, a:%d, b:%d, c:%d\n", this->_a, this->_b, this->_c);
	}
	int getA() {
		return this->_a;
	}
protected:
private:
	int _a;
	int _b;
	int _c;
};

class MyE {
public:
	MyE() :abcd1(1, 2, 3), abcd2(4, 5, 6), m(100) {
		cout << "MyE()" << endl;
	}
	~MyE() {
		cout << "~MyE()" << endl;
	}
	MyE(const MyE &obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100) {
		printf("MyE(const MyE &obj)\n");
	}
protected:
public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;
};

int doThing(MyE mye1) {
	printf("doThing() mye1.abcd1.a:%d\n", mye1.abcd1.getA());
	return 0;
}

int run2() {
	printf("run2 start..\n");
	//由于作用域，对象会在函数调用完成的时候依次出栈析构
	MyE myE;
	doThing(myE);
	return 0;
}

int run3() {
	printf("run3 start..\n");
	ABCD(400, 500, 600);//临时对象的生命周期
	//ABCD a = ABCD(100, 200, 300);
	//是否可以直接在一个构造函数中调用另一个构造函数?
	//不可以，由于变量的作用域，该对象在构造函数执行完成之后被析构
	return 0;
}

//测试构造函数中调用构造函数
class MyTest {
public:
	MyTest(int a, int b, int c) {
		this->_a = a;
		this->_b = b;
		this->_c = c;
	}
	MyTest(int a, int b) {
		this->_a = a;
		this->_b = b;

		MyTest(a, b, 100);
	}
	~MyTest() {
		printf("~Mytest:%d,%d,%d\n", _a, _b, _c);
	}

protected:
private:
	int _a;
	int _b;
	int _c;

public:
	int getC() const { return _c; }
	void setC(int val) { _c = val; }
};


int main011() {
	run2();
	//run3();
	//MyTest t1(1, 2);
	//printf("c:%d\n", t1.getC());//c的值?
	system("pause");
	return 0;
}