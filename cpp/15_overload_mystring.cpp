#include "stdafx.h"
#include <iostream>

using namespace std;

class MyString {
public:
	MyString() {
		const char *tmp = "default value";
		m_len = strlen(tmp);
		m_str = new char[m_len + 1];
		strcpy_s(m_str, m_len + 1, tmp);
	}
	MyString(const char *str) {
		if (str != NULL) {
			m_len = strlen(str);
			m_str = new char[m_len + 1];
			strcpy_s(m_str, m_len + 1, str);
		}
	}
	MyString(const MyString &obj) {
		if (obj.m_str != NULL) {
			m_len = obj.m_len;
			m_str = new char[m_len + 1];
			strcpy_s(m_str, m_len + 1, obj.m_str);
		}
	}
	~MyString() {
		if (m_str != NULL) {
			delete[] m_str;
			m_str = NULL;
			m_len = 0;
		}
	}
public:
	void printout() {
		if (m_str == NULL)
		{
			cout << "obj non initialization" << endl;
			return;
		}
		cout << m_str << endl;
	}
public:
	friend ostream& operator<<(ostream &out, MyString &obj);//1 <<
	friend istream& operator>>(istream &in, MyString &obj);//2 >>
	MyString& operator=(MyString &obj) {//3 =
		if (m_str != NULL)
		{
			delete[] m_str;
			m_str = NULL;
			m_len = 0;
		}
		m_len = obj.m_len;
		m_str = new char[m_len + 1];
		strcpy_s(m_str, m_len + 1, obj.m_str);
		return *this;
	}
	bool operator==(MyString &obj) {//4 !=
		if (m_len != obj.m_len)
			return false;
		for (int i = 0; i < m_len; i++)
		{
			if (m_str[i] != obj.m_str[i])
				return false;
		}
		return true;
	}
	bool operator!=(MyString &obj) {//5 ==
		return !(*this == obj);
	}
	bool operator>(MyString &obj) {//6 >
		if (m_len == 0 || m_len < obj.m_len)
			return false;
		if (m_len == obj.m_len) {
			return strcmp(m_str, obj.m_str);
		}
		return true;
	}
	bool operator<(MyString &obj) {//7 <
		return !(*this > obj);
	}
private:
	char* m_str;
	int m_len;
};

ostream& operator<<(ostream &out, MyString &obj) {
	out << obj.m_str;
	return out;
}

istream& operator>>(istream &in, MyString &obj) {
	for (int i = 0; i < obj.m_len; i++)
		in >> obj.m_str[i];
	return in;
}

int main155() {
	//<<, >>, !=, ==, >, <, =
	MyString obj1;
	obj1.printout();
	//1 <<
	cout << "Test <<: " << obj1 << "end" << endl;
	//cout.operator<<(obj1)
	//void operator<<(ostream &out, MyString &obj)

	MyString obj2("dddd");
	obj2.printout();
	//2 >>
	cin >> obj2;
	//cin.operator(obj2)
	//istream& operator(istream &in, MyString &obj)
	cout << "Test >>: ";
	obj2.printout();

	MyString obj3;
	//3 =
	obj3 = obj2;
	//obj3.operator=(obj2)
	//MyString& operator=(MyString &obj3, MyString &obj2)
	cout << "Test =: ";
	obj3.printout();


	//4 !=
	if (obj2 != obj1) {
		//bool operator!=(MyString &obj1)
		cout << "Test !=: obj2 not equal obj1" << endl;
	}
	else
	{
		cout << "Test !=:obj2 equal obj1" << endl;
	}

	//5 ==
	if (obj3 == obj1) {
		//bool operator!=(MyString &obj1)
		cout << "Test ==: obj3 equal obj1" << endl;
	}
	else
	{
		cout << "Test ==:obj3 not equal obj1" << endl;
	}

	//6 >
	if (obj1 > obj2)
		cout << "Test >: " << "obj1 > obj2" << endl;
	else
		cout << "Test >: " << "obj1 < obj2" << endl;
	//bool operator>(MyString &obj)

	//7 <
	if (obj3 < obj1)
		cout << "Test <: " << "obj3 < obj1" << endl;
	else
		cout << "Test <: " << "obj3 > obj1" << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
