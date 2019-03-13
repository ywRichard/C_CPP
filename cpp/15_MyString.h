#pragma once
#include <iostream>

using namespace std;

class MyString {
	//<< >>
	friend ostream& operator<<(ostream &out, MyString &obj);
	friend istream& operator>>(istream &in, MyString &obj);
public:
	MyString(int len=0);
	MyString(const char *p);
	MyString(const MyString &s);
	~MyString();
public:
	//=, [],
	MyString & operator=(const char *p);
	MyString& operator=(const MyString &s);
	//s[1]
	char& operator[](int index);
public:
	//== !=
	bool operator==(const char *p) const;
	bool operator==(const MyString &s) const;
	bool operator!=(const char *p) const;
	bool operator!=(const MyString &s) const;
	//< >
	bool operator<(const char *p) const;
	bool operator>(const char *p) const;
	bool operator<(const MyString &s) const;
	bool operator>(const MyString &s) const;
private:
	int m_len;
	char *m_p;
};