#include "stdafx.h"
#include "iostream"
using namespace std;

class Location {
public:
	Location(int x, int y) {
		_x = x;
		_y = y;
	}
	Location(const Location &obj) {
		_x = obj._x;
		_y = obj._y;
		cout << "copy constructor was called" << endl;
	}
	~Location() {
		cout << " a:" << _x << " b:" << _y << endl;
	}
	int getX() { return _x; }
	int getY() { return _y; }

private:
	int _x, _y;
	char *_str;
};

//3.对象实参传值给形参的时候，会调用copy构造函数
void f(Location p) {
	cout << p.getX() << endl;
}

void playObj()
{
	Location myLa(1, 2);
	Location b=myLa;
	cout << "b obj initialized" << endl;

	f(b);
}

//4.函数返回值是一个对象 -> 编译器会类的copy构造函数 返回一个匿名的对象
Location g() {
	Location A(1, 2);
	return A;
}

void playObj2() {
	g();
}

void playObj3() {
	Location m = g();//匿名对象直接被初始化为m
	cout << "匿名对象被扶正，不会被析构\n" << endl;
	cout << m.getX() << endl;
}

void playObj4() {
	Location m2(3, 4);
	m2 = g();//m2已经被初始化，匿名对象不会被扶正
	cout << "赋值给m2之后被析构" << endl;
	cout << m2.getX() << endl;
}

int main063() {
	Location l0(5, 6);
	Location ln(1, 2);
	//1.第一种调用方法
	Location l1 = l0;//l1 initialize l2
	//赋值=操作，不会调用copy构造函数，operator = 操作符重载
	ln = l1;

	//2.第二种调用方法
	Location l2(l0);

	//playObj();
	//playObj2();
	//playObj3();
	playObj4();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}