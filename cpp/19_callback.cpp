#include "stdafx.h"
#include <iostream>

using namespace std;

int MyAdd(int a, int b) {//子任务的实现者
	cout << "func myAdd: " << a << " + " << b << endl;
	return a + b;
}

typedef int(*MyTypeFuncAdd)(int a, int b);

int MainOp(MyTypeFuncAdd myFuncAdd) {
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int(*myFuncPoint)(int a, int b)) {
	int c = myFuncPoint(7, 8);
	return c;
}

int main() {
	MyTypeFuncAdd myFuncAdd = NULL;
	MyAdd(1, 2);//直接调用

	myFuncAdd = MyAdd;
	myFuncAdd(3, 4);

	MainOp(MyAdd);
	//MainOp2(&MyAdd);
	MainOp2(MyAdd);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
