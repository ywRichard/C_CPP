#include "stdafx.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class Teacher {
public:
	Teacher(int age) {
		if (age > 100) {
			throw out_of_range("age overlimit");
		}
		this->m_age = age;
	}
private:
	int m_age;
};

int main01() {
	try{
		Teacher t1(1000);
	}
	catch (out_of_range &e){
		cout << e.what() << endl;
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

class MyExcept :public exception {
public:
	MyExcept(const char *p) {
		this->m_p = const_cast<char*>(p);
	}
	virtual const char *what() {
		cout << "MyException: type " << this->m_p << endl;
		return this->m_p;
	}
private:
	char *m_p;
};

void TestMyExcept() {
	throw MyExcept("func throw exception");
}

int main() {
	try {
		TestMyExcept();
	}
	catch (MyExcept &e) {
		e.what();
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}


