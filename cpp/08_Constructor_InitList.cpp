#include "stdafx.h"
#include "iostream"

using namespace std;

class A {
public:
	A(int a) {
		_a = a;
		cout << _a<<":init A done" << endl;
	}
protected:
private:
	int _a;
};

//1.构造函数的初始化列表 解决：在B类中初始化嵌套的A类
//若A自定义了构造函数，则必须要显示调用自定义的构造函数，编译器不再调用默认的无参构造函数
//syntax： Constructor::Constructor():m1(a),m2(b)...

//2.初始化顺序，按成员的定义顺序，而不是初始化列表的排列顺序
//析构函数顺序相反（栈结构，FILO）

//3.const成员必须在初始化列表中赋值，而不能在构造函数中。
//因为开始调用构造函数时，const成员变量已经初始化完成，不能在赋值了。
class B {
public:
	B(int b1, int b2, int m, int n) :_a1(m), _a2(n), _c(0) {
		_b1 = b1;
		_b2 = b2;
		cout << "B's constructor" << endl;
	}
	~B() {
		cout << "B's destructor" << endl;
	}
protected:
private:
	A _a2;
	A _a1;
	int _b1;
	int _b2;
	const int _c;
};

void objplay() {
	//A a1(10);
	//assign parameter
	B objB(1, 2, 3, 4);
}
int main08() {
	objplay();
	cout << "main finished" << endl;
	system("pause");
	return 0;
}