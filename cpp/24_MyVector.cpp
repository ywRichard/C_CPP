#include "stdafx.h"
#include <iostream>
#include "24_MyVector.h"

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const MyVector<T> &obj) {
	for (int i = 0; i < obj.m_len; i++)
	{
		out << obj.m_space[i] << " ";
	}
	out << endl;
	return out;
}

template<typename T>
MyVector<T>::MyVector(int size) {//constructor
	m_len = size;
	m_space = new T[m_len];
}

template<typename T>
MyVector<T>::MyVector(const MyVector &obj) {//deep copy constructor
	m_len = obj.m_len;
	m_space = new T[m_len];
	//cpy
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector() {//destructor
	if (m_space != NULL) {
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

template<typename T>
T& MyVector<T>::operator[](int index) {
	return m_space[index];
}

//a3=a2=a1
template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &obj) {
	//1.release memory
	if (m_space != NULL) {
		delete[] m_sapce;
		m_space = NULL;
		m_len = 0;
	}
	//2.allocate memory
	m_len = obj.m_len;
	m_space = new T[m_len];

	//3.cpy
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj[i];
	}
	return *this;//a2 = a1, return &a2
}
