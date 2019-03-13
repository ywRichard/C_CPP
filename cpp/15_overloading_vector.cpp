#include "stdafx.h"
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector(int size = 1);
	~Vector();
	int& operator[](int i);
	friend ostream& operator<<(ostream& output, Vector&);
	friend istream& operator>>(istream& input, Vector&);
private:
	int* v;
	int len;
};

Vector::Vector(int size)
{
	if (size < 0 || size>100) {
		cout << "The size of " << size << " is null!\n";
		abort();
	}
	v = new int[size];
	len = size;
}

Vector::~Vector()
{
	delete[] v;
	len = 0;
}

int & Vector::operator[](int i)
{
	if (i >= 0 && i <= len)
		return v[i];
	cout << "The subscript " << i << " is outside !\n";
	abort();
}

ostream & operator<<(ostream & output, Vector& ary)
{
	for (int i = 0; i < ary.len; i++)
	{
		output << ary[i] << " ";
	}
	output << endl;
	return output;
}

istream & operator>>(istream &input, Vector &ary)
{
	for (int i = 0; i < ary.len; i++)
	{
		input >> ary[i];
	}
	return input;
}

int main154() {
	int k;
	cout << "Input the length of vector A:\n";
	cin >> k;
	Vector A(k);
	cout << "Input the elements of vector A:\n";
	cin >> A;
	cout << "Output the elements of vector A:\n";
	cout << A;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}