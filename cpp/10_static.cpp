#include "stdafx.h"
#include "iostream"

using namespace std;

class BB {
public:
	void printC() {
		cout << "c:" << endl;
	}
	void AddC() {
		c++;
	}
	static void getC() {
		cout << "c:" << c << endl;
		//静态函数中只能使用静态成员
		//cout << "a:" << a << endl;//E0245	a nonstatic member reference must be relative to a specific object

	}
protected:
private:
	int a;
	int b;
	static int c;
};

//为static成员变量分配内存空间，不能省略
//隐患->不分配内存（不写），编译器不报错
int BB::c = 10;

class C2 {
public:
	int i;
	int j;
	int k;

	static int m;
public:
	int getK() const { return k; }
	void setK(int val) { k = val; }
};

struct S1 {
	int i;
	int j;
	int k;

};

struct S2 {
	int i;
	int j;
	int k;
	static int m;
};

int main10() {
	BB b1, b2, b3;
	b1.printC();//10
	b2.AddC();//11
	b3.printC();//11

	//静态成员函数的调用方法
	b3.getC();//对象
	BB::getC();//::类的作用域

	//deep in static
	{

		cout << "C2:" << sizeof(C2) << endl;
		cout << "S1:" << sizeof(S1) << endl;
		cout << "S2:" << sizeof(S2) << endl;
	}

	return 0;
}

