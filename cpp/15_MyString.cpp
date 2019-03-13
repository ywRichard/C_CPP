#include "stdafx.h"
#include <iostream>

#include "15_MyString.h"

MyString::MyString(int len) {
	m_len = len;
	m_p = new char[m_len + 1];

	memset(m_p, 0, m_len);
}

MyString::MyString(const char *p) {
	if (p == NULL) {
		m_len = 0;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
	}
	else {
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy_s(m_p, m_len + 1, p);
	}
}

MyString::MyString(const MyString &s) {
	m_len = s.m_len;
	m_p = new char[m_len + 1];

	strcpy_s(m_p, m_len + 1, s.m_p);
}

MyString::~MyString() {
	if (m_p != NULL)
	{
		delete[] m_p;
		m_p = NULL;
		m_len = 0;
	}
}

MyString& MyString::operator=(const char *p)
{
	if (m_p != NULL) {
		delete[] m_p;
		m_p = NULL;
		m_len = 0;
	}

	if (p == NULL) {
		m_len = 0;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);
	}
	else {
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy_s(m_p, m_len + 1, p);
	}

	return *this;
}

MyString& MyString::operator=(const MyString & s)
{
	if (m_p != NULL) {
		delete[] m_p;
		m_p = NULL;
		m_len = 0;
	}

	m_len = s.m_len;
	m_p = new char[m_len];
	strcpy_s(m_p, m_len + 1, s.m_p);

	return *this;
}

char& MyString::operator[](int index)
{
	if (index <= m_len)
	{
		return m_p[index];
	}
	else
	{
		cout << "index out of array bound" << endl;
		abort();
	}
}

bool MyString::operator==(const char *p) const
{
	if (p == NULL)
	{
		if (m_len == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (this->m_len != strlen(p))
			return false;
		else
			return !strcmp(m_p, p);
	}
}

bool MyString::operator==(const MyString &s) const
{
	if (this->m_len != s.m_len)
		return false;
	else
		return !strcmp(this->m_p, s.m_p);
}

bool MyString::operator!=(const char * p) const
{
	return !(this->m_p == p);
}

bool MyString::operator!=(const MyString & s) const
{
	return !(this->m_p == s.m_p);
}

//s<p
bool MyString::operator<(const char * p) const
{
	if (p == NULL)
		return false;
	else
		return strcmp(this->m_p, p) < 0;
}

bool MyString::operator>(const char * p) const
{
	if (p == NULL)
		return true;
	else
		return strcmp(p, this->m_p) > 0;
}

bool MyString::operator<(const MyString & s) const
{
	return strcmp(this->m_p, s.m_p) < 0;
}

bool MyString::operator>(const MyString & s) const
{
	return strcmp(s.m_p, this->m_p) > 0;
}

ostream& operator<<(ostream& out, MyString& obj)
{
	out << obj.m_p;
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	in >> obj.m_p;
	return in;
}