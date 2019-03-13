#include "stdafx.h"
#include "iostream"
#include <string.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Name {
public:
	Name(const char *myp) {
		m_len = strlen(myp);
		m_p = (char *)malloc(m_len + 1);
		strcpy_s(m_p, m_len + 1, myp);
	}
	//a default copy constructor will just cope the value of member variables.
	//for complicated data type, it will lead dangling pointer issue and doule free heap memory
	//solution: implement a copy constructor to manually allocate a memory for the pointer.
	Name(const Name &obj1) {
		m_len = obj1.m_len;
		m_p = (char*)malloc(m_len + 1);
		strcpy_s(m_p, m_len + 1, obj1.m_p);
	}
	~Name() {
		if (m_p != NULL) {
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}

protected:
private:
	char *m_p;
	int m_len;
};

void objplaymain() {
	Name obj1("abcdefg");
	//Name obj2 = obj1; //call customized copy constructor
	Name obj3 = ("obj3");
	obj3 = obj1;// assign operator, won't call copy constructor.
}

int main07() {
	objplaymain();
	cout << "hello..." << endl;

	system("pause");
	return 0;
}