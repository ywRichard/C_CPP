#include "stdafx.h"
#include <iostream>

using namespace std;

//overload, overwrite & redefine
//overload -> 函数在1个类里面，根据参数的类型和数量的不同发生overload

//overwrite -> 发生在2个类之间
//1.virtual函数的overwrite 是 polymorphsiam (virtual真正的应用场景)
//2.非virtual函数的overwrite 是 redefine
class Parent {
public:
	void abc() {
		printf("Parent's abc\n");
	}
	//below is overload
	virtual void func() {
		cout << "func() do..." << endl;
	}
	virtual void func(int i) {
		cout << "func(int i) do..." << i << endl;
	}
	virtual void func(int i, int j) {
		cout << "func(int i, int j) do..." << i << " " << j << endl;
	}
};

class Child :public Parent {
public:
	void abc() {
		printf("Child's abc\n");
	}
	virtual void func(int i, int j) {
		cout << "func(int i, int j) do... " << i << " " << j << endl;
	}
	virtual void func(int i, int j, int k) {
		cout << "func(int i, int j, int k) do... " << i << " " << j << " " << k << endl;
	}
};

//overload, overwrite & redefine
int main() {
	Child c1;

	//E0304	no instance of overloaded function "Child::func"
	//c1.func();//子类无法重载父类的函数, 父类与子类同名的函数将被子类的覆盖
	c1.Parent::func();//若要调用, 必须用 域作用符 显示的标注

	//1.c++编译器不会去父类找4的参数的func函数。因子类中已有func函数名， 父类的func名称被覆盖。
	//2. ...只会在子类中查找func, 只有带2个和3个参数的func。没有4个参数的func
	//3. ...报错, E0304	no instance of overloaded function "Child::func"
	//4. 若要调用, 必须用 域作用符 显示的标注 c1.Parent::func()
	//c1.func();//E0304	no instance of overloaded function "Child::func"




	cout << "hello..." << endl;
	system("pause");
	return 0;
}
