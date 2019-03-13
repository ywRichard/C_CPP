#include "stdafx.h"
#include <iostream>

using namespace std;

//generic programming
//让类型参数化，方便程序员进行编程
template <typename T>
//template<typename T, typename T2>
void mySwap(T &a, T &b) {
	T c;
	c = a;
	a = b;
	b = c;

	cout << "call template" << endl;
}

//函数模板的调用
int main01() {
	{
		int x = 10;
		int y = 20;

		mySwap<int>(x, y);//1.函数模板 显示类型 调用
		//mySwap(x, y);//2.自动类型 推导
		printf("x:%d, y:%d\n", x, y);
	}

	{
		char a = 'a';
		char b = 'b';

		mySwap<char>(a, b);
		printf("a:%c,b:%c\n", a, b);
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

//函数模板 本质：类型参数化
//对字符数组, int数组进行排序
template<typename T, typename T1>
int mySort(T *array, T1 size) {
	T tmp;
	if (array == NULL) {
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i] < array[j]) {
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}

	return 0;
}

template<typename T, typename T1>
int myPrint(T *array, T1 size) {
	T1 i = 0;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}

int main() {
	//int
	{
		int myArray[] = { 11,22,44,33,5,3.8,6 };

		int size = sizeof(myArray) / sizeof(*myArray);
		mySort<int, int>(myArray, size);

		printf("排序之后\n");
		myPrint<int, int>(myArray, size);
	}

	//char
	{
		char buf[] = "qwertasdf";
		int len = strlen(buf);

		mySort<char, int>(buf, len);
		myPrint<char, int>(buf, len);
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

