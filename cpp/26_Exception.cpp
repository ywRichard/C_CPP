#include "stdafx.h"
#include <iostream>

using namespace std;

//1.基本语法
//2.发生异常之后
//3.接受异常之后, 可以不处理 再抛出
//4.catch异常时, 按照类型进行catch
//5.异常捕捉严格按照类型匹配

void divide(int x, int y) {
	if (y==0){
		throw x;//throw exception
	}

	cout << "divide result: " << x / y << endl;
}

void myDivide(int x, int y) {
	divide(x, y);
}

void myDivide1(int x, int y) {
	try{
		divide(x, y);
	}
	catch (...){
		cout << " throw the exception without any handler" << endl;
		throw;
	}
}
int main01() {
	try {
		divide(10, 2);
		divide(100, 0);

		myDivide(100, 0);
	}
	catch (int e){
		cout << e << "divide 0" << endl;
	}
	catch (...) {
		cout << "other unknow exception" << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

int main() {

	try {
		throw 'z';
	}
	catch(int i){
		cout << "catch int exception" << endl;
	}
	catch(...){
		cout << "unknown exception" << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}