#include "stdafx.h"
#include <iostream>

//重点是直接调用cpp源文件而不是头文件
#include "22_Complex.cpp"

using namespace std;

int main() {
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	c3.printCom();
	cout << c3 << endl;

	Complex<int> c4 = c1 - c2;
	c4.printCom();
	cout << c4 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
