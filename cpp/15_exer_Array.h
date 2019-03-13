#pragma once

#include "iostream"
using namespace std;

class MyArray {
public:
	MyArray(int length);
	MyArray(const MyArray &obj);
	~MyArray();
	int& operator[](int i);
	MyArray& operator=(MyArray & array);
	bool operator==(MyArray& a);
	bool operator!=(MyArray& a);

public:
	void setData(int index, int value);
	int getData(int index);
	int length();
protected:
private:
	int m_length;
	int *m_space;
};