#include "stdafx.h"
#include "iostream"
#include "13_Array.h"

using namespace std;

void main13() {
	Array a1(10);

	for (int i = 0; i < a1.length(); i++)
	{
		a1.setData(i, i);
	}
	
	cout << "print a1" << endl;
	for (int i = 0; i < a1.length(); i++)
	{
		cout << a1.getData(i) << " ";
	}
	cout << endl;

	Array a2 = a1;
	cout << "print a2" << endl;
	for (int i = 0; i < a2.length(); i++)
	{
		cout << a2.getData(i) << " ";
	}
	cout << endl;

	cout << "hello..." << endl;
	system("pause");
	return;
}
