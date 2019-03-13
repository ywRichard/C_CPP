#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//01 basic data type
int main01() {
	vector<int> v1;//1. container --> 储存我的元素
	v1.push_back(-1);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(3);

	//2.iterator -> 是一个指针, 对指定范围进行寻址操作
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1:" << num1 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

class Teacher {
public:
	Teacher(int age, const char *name) {
		this->age = age;
		strcpy_s(this->name, name);
	}
public:
	int age;
	char name[64];
};

//02 custimzed element
int main02() {
	vector<Teacher> v1;
	Teacher t1(1, "t1"), t2(2, "t2"), t3(3, "t3");//需要深copy的对象不能被加入到vector中
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//2.iterator
	for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << it->age << " ";
	}
	cout << endl;

	//对于自定义的元素, 要使用stl的算法需要根据算法的要求重载一些操作符。
	//int num1 = count(v1.begin(), v1.end(), 3);
	//cout << "num1:" << num1 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

//03 custimzed element
int main() {
	vector<Teacher*> v1;
	Teacher t1(1, "t1"), t2(2, "t2"), t3(3, "t3");

	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//2.iterator
	for (vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << (*it)->age << " ";
	}
	cout << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}