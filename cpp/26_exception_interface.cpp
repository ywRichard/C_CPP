#include "stdafx.h"
#include <iostream>

using namespace std;

/*statement the exception type throw in a func*/
class MyTest {
public:
	MyTest(int a, int b) {
		this->a = a;
		this->b = b;
		printf("MyTest(a:%d,b:%d)\n", this->a, this->b);
	}
	~MyTest() {
		printf("~MyTest(a:%d,b:%d)\n", this->a, this->b);
	}
private:
	int a;
	int b;
};

//1. limited thrown data type by statement
void MyFunc() throw(int, char, char*){ 
	MyTest t1(1, 2), t2(3, 4);
	cout << "myDivide... throw exception." << endl;
	throw t1;
}
//2. Throw exception of any datatype
void MyFunc1()  {
	MyTest t1(1, 2), t2(3, 4);
	cout << "myDivide... throw exception." << endl;
	throw 1;
}
//3. Won't be able to throw any exception
void MyFunc2() throw() {
	MyTest t1(1, 2), t2(3, 4);
	cout << "myDivide... throw exception." << endl;
	throw 2;
}

/*statement the exception type throw in a func*/

int main01() {
	try
	{
		MyFunc();
		MyFunc2();
	}
	catch (MyTest t)
	{
		cout << "My Test Exception" << endl;
	}
	catch (...) {
		cout << "unknown exception" << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
