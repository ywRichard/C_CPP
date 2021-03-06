// CPPDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string>
#include <string.h>
using namespace std;
//1.the head file, "iostream", doesn't refer the namespace, std.
//2.We need to add the std namespace manually if we didn't refer it.
int main01()
{
	std::cout << "namespace test" << std::endl;
    return 0;
}

//3.define customized namespace
namespace namespaceA {
	int a = 10;
}

namespace namespaceB {
	int a = 20;
	namespace namespaceC {
		struct Teacher {
			char name[10];
			int age;
		};
	}
}

void main02() {
	using namespace namespaceA;
	using namespace namespaceB;
	//cout << a << endl;
	cout << namespaceA::a << endl;
	cout << namespaceB::a << endl;

	//4.namespace nested call
	{
		namespaceB::namespaceC::Teacher t1;
		t1.age = 30;
	}
	//5.To state a data type in a namespce.
	using namespaceB::namespaceC::Teacher;
	Teacher t2;
	t2.age = 36;

	system("pause");



}

