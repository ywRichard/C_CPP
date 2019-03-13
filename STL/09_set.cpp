#include "stdafx.h"
#include <iostream>
#include <set>

using namespace std;

void printS(set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

/*
1.set
	a.元素唯一,值不相同;
	b.自动排序, 默认 小->大
	c.不同用[]方式插入元素
*/
void test_1() {
	set<int> s;
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		s.insert(tmp);
	}
	s.insert(100);
	s.insert(100);//插入重复的元素会失败
	s.insert(100);
	printS(s);

	while (!s.empty()) {
		set<int>::iterator it = s.begin();
		cout << *it << " ";
		s.erase(s.begin());
	}
	cout << endl;
}

/*
基本数据类型, set能自动排序
*/
void test_2() {
	set<int> s;
	//等价 set<int, less<int>> s2;//默认 函数对象 less<int>

	set<int, greater<int>> s3;//大 -> 小
	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();
		s3.insert(tmp);
	}

	for (set<int, greater<int>>::iterator it = s3.begin(); it != s3.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class Student {
public:
	Student(const char *name, int age) {
		strcpy_s(this->name, name);
		this->age = age;
	}
public:
	char name[64];
	int age;
};

//仿函数
struct FuncStudent {
	bool operator()(const Student &left, const Student &right) {
		if (left.age < right.age)//从 小到大 排序
			return true;
		else
			return false;
	}
};

//仿函数的用法
void test_3() {
	Student s1("s1", 31);
	Student s2("s2", 22);
	Student s3("s3", 44);
	Student s4("s4", 11);
	//Student s5("s5", 31);//插入相同的值会失败

	set<Student, FuncStudent> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);

	for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); it++) {
		cout << it->age << "\t" << it->name << endl;
	}
}

//判断set.insert()返回值 --> set的元素是唯一的, 插入相同的值会失败
//using _Pairib = pair<iterator, bool>;
void test_4() {
	Student s1("s1", 31);
	Student s2("s2", 22);
	Student s3("s3", 44);
	Student s4("s4", 11);
	Student s5("s5", 31);

	set<Student, FuncStudent> set1;
	pair<set<Student, FuncStudent>::iterator, bool>pair1 = set1.insert(s1);
	if (pair1.second == true) {
		cout << "set1.insert(s1) successfully" << endl;
	}
	else {
		cout << "set1.insert(s1) failed" << endl;
	}

	pair<set<Student, FuncStudent>::iterator, bool>pair5 = set1.insert(s5);
	if (pair5.second == true) {
		cout << "set1.insert(s5) successfully" << endl;
	}
	else {
		cout << "set1.insert(s5) failed" << endl;
	}
}

//find 查找 equal_range
//return pair
void test_5() {
	set<int> s;
	for (int i = 0; i < 10; i++){
		s.insert(i + 1);
	}
	printS(s);

	set<int>::iterator it0 = s.find(5);
	cout << "it0:" << *it0 << endl;

	int num1 = s.count(5);
	cout << "num1:" << num1 << endl;

	set<int>::iterator it1 = s.lower_bound(5);// 大于等于 5的元素的 迭代器位置
	cout << "it1:" << *it1 << endl;
	set<int>::iterator it2 = s.upper_bound(5);//返回 第一个大于5 的元素的迭代器位置
	cout << "it2:" << *it2 << endl;

	//删掉元素5, 再去找元素5
	s.erase(5);
	//using _Pairii = pair<iterator, iterator>;
	pair<set<int>::iterator, set<int>::iterator> mypair = s.equal_range(5);
	set<int>::iterator it3 = mypair.first;
	cout << "it3:" << *it3 << endl;//5, 6
	
	set<int>::iterator it4 = mypair.second;
	cout << "it4:" << *it4 << endl;//6, 6
}

int main() {
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	test_5();


	cout << "hello..." << endl;
	system("pause");
	return 0;
}
