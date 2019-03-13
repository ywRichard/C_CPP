#include "stdafx.h"
#include "15_exer_Array.h"

MyArray::MyArray(int length) {
	if (length < 0)
	{
		length = 0;
	}
	m_length = length;

	m_space = new int[m_length];
}

MyArray::MyArray(const MyArray &obj) {

}

MyArray::~MyArray()
{
}

//1.a[i]=i, 2.int b = a[i]
int & MyArray::operator[](int i)
{
	return m_space[i];
}

//3.a3=a2=a1
MyArray& MyArray::operator=(MyArray& a)
{
	//1.release
	if (this->m_space != NULL) {
		delete[] m_space;
		m_length = 0;
	}

	//2.allocate
	m_length = a.length();
	m_space = new int[m_length];

	//3.copy
	for (int i = 0; i < m_length; i++)
	{
		m_space[i] = a.m_space[i];
	}

	return *this;
}

//(a3 == a1)
bool MyArray::operator==(MyArray& a)
{
	if (m_length != a.m_length)
		return false;

	for (int i = 0; i < m_length; i++)
	{
		if (m_space[i] != a.m_space[i])
			return false;
	}
	return true;
}

//(a3 != a1)
bool MyArray::operator!=(MyArray& a)
{
	return !(*this == a);
}

void MyArray::setData(int index, int value) {
	m_space[index] = value;
}

int MyArray::getData(int index) {
	return m_space[index];
}

int MyArray::length()
{
	return m_length;
}


