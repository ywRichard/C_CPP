#include "stdafx.h"
#include "15_exer_Array.h"

using namespace std;

int main157() {
	MyArray a1(10);
	for (int i = 0; i < a1.length(); i++)
	{
		//a1.setData(i, i);

		//2. [] as left value
		a1[i] = i;//return a reference as a left value
		//operator[](a,i)
	}

	cout << "print a1:";
	for (int i = 0; i < a1.length(); i++)
	{
		//cout << a1.getData(i) << endl;

		//1. [] as a value
		cout << a1[i]<<" ";;
		//int a.operator[](i)
		//int& a.operator[](i)
	}
	cout << endl;

	MyArray a2 = a1;
	cout << "print a2:";
	for (int i = 0; i < a2.length(); i++)
	{
		//cout << a2.getData(i) << endl;
		cout << a2[i]<<" ";
	}
	cout << endl;

	MyArray a3(5);
	{
		//3. =
		a3 = a2 = a1;
		//int& a2.operator=(a1)
		//int& operator(MyArray& a)
		cout << "print a3:";
		for (int i = 0; i < a3.length(); i++)
		{
			cout << a3[i] << " ";
		}
		cout << endl;
	}

	//4. ==, !=
	//a3.operator==(a1)
	//MyArray& operator==(MyArray& a)
	if (a3 == a1)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
	//a3.operator!=(a1)
	//MyArray& operator!=(MyArray& a)
	if (a3 != a1)
	{
		cout << "not equal" << endl;
	}
	else
	{
		cout << "equal" << endl;
	}

	cout << "hello" << endl;
	system("pause");

	return 0;
}