#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename T>
class MyVector {
	friend ostream &operator<< <T>(ostream &out, const MyVector &obj);
public:
	MyVector(int size = 0);//constructor
	MyVector(const MyVector &obj);//deep copy constructor
	~MyVector();//destructor
public:
	T & operator[](int index);
	MyVector &operator=(const MyVector &obj);
public:
	int getLen() {
		return m_len;
	}
protected:
	T * m_space;
	int m_len;
};
