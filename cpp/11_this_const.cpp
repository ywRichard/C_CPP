#include "stdafx.h"
#include "iostream"

using namespace std;

class Test {
public:
	Test(int a, int b) {
		this->_a = a;
		this->_b = b;
	}
	void printT() {
		cout << "_a:" << _a << endl;
		cout << "_b:" << this->_b << endl;
	}
	//1.const 可以在函数名称的前面或者后面
	//2.const 修饰的this指针所指向的内存空间，修饰的是this指针
	//void OpVar(int a, int b)  //==> void OpVar(Test *const this, int a, int b) 

	//void const OpVar(int a, int b)  
	//const void  OpVar(int a, int b)
	void OpVar(int a, int b) const { //==> void OpVar(const Test *const this, int a, int b)  
		a = 100;
		//this->_b = 200;

		cout << "b:" << this->_b << endl;
	}
protected:
private:
	int _a;
	int _b;
};

int main11() {
	int *my_space = new int[0];
	if (my_space == NULL) {
		return 0;
	}
	Test t1(1, 2);
	t1.printT();//==> printT(&t1)

	return 0;
}