#include "stdafx.h"
#include <iostream>

using namespace std;

class Name
{
public:
	Name(const char *myp) {
		m_len = strlen(myp);
		m_p = new char[m_len + 1];
		strcpy_s(m_p, m_len + 1, myp);
	}
	//deep copy
	Name(const Name& obj) {
		m_len = obj.m_len;
		m_p = new char[m_len + 1];
		strcpy_s(m_p, m_len + 1, obj.m_p);
	}
	~Name() {
		if (m_p != NULL)
		{
			delete[] m_p;
			m_p = NULL;
			m_len = 0;
		}
	}
	//obj3=obj2=obj1
	Name& operator=(Name& obj) {
		//1.release memory
		if (this->m_p != NULL) {
			delete[] m_p;
			m_len = 0;
		}
		//2.allocate new memory
		m_len = obj.m_len;
		m_p = new char[m_len + 1];
		//3.set value
		strcpy_s(m_p, m_len + 1, obj.m_p);

		return *this;// as left value
	}

	void printout() {
		cout << m_p << endl;
	}

private:
	char *m_p;
	int m_len;
};

void objplaymain1() {
	Name obj1("obj1 abcdef");
	Name obj2("obj2");
	obj2.printout();
	obj2 = obj1;//= is equivalent to swallow copy 
	obj2.printout();
	//obj2.operator=(obj1)
	//void operator=(Name& obj)
	
	Name obj3("obj3");
	obj3.printout();
	obj3 = obj2 = obj1;
	obj3.printout();

	//obj3=obj2=obj1
}

int main154() {
	objplaymain1();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
