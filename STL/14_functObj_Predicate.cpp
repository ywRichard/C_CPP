#include "stdafx.h"
#include <iostream>

using namespace std;

#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

// function object is a class operator overwirte ()
template <typename T>
class ShowElemt {
public:
	ShowElemt() {
		n = 0;
	}
	void operator()(T &t) {//重载了()类 --> 函数对象/ 仿函数/ 谓词
		n++;
		//printN();
		cout << t << endl;
	}
	void printN() {
		cout << "n:" << n << endl;
	}
private:
	int n;
};

//template func
template<typename T>
void FuncShowElemt(T &t) {
	cout << t << endl;
}

//general func
void FuncShowElemt2(int a) {
	cout << a << " ";
	//cout << a << endl;
}

//函数对象 vs 模板函数/普通函数 异同
void test_1() {
	int a = 10;
	ShowElemt<int> showElemt;
	showElemt(a);//相同点, 函数对象的调用方式和普通函数相似
	FuncShowElemt<int>(a);
	FuncShowElemt2(a);
}

//函数对象 本质是 类对象; 好处就是可以突破函数的概念, 能保持调用状态的信息
//
void test_2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), ShowElemt<int>());//匿名函数对象的调用/ 匿名仿函数
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElemt<int>);
	for_each(v1.begin(), v1.end(), FuncShowElemt2);//回调函数

	ShowElemt<int> show1;
	/*
		template<class _InIt,
		class _Fn> inline
		_Fn for_each(_InIt _First, _InIt _Last, _Fn _Func)
		{
		...
		return (_Func);
		}
	*/
	//for_each算法中, 
	//1.函数对象做函数参数, 传递的是 元素 而不是 引用
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();

	//2.函数对象做返回值
	cout << "for_each return value:" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);
	show1.printN();

	//结论: 重点是要分清 stl算法 return的是 iterator 还是 谓词/函数对象; STL算法入门的重点
}

template <typename T>
class IsDiv {
public:
	IsDiv(const T &divisor) {
		this->divisor = divisor;
	}
	bool operator()(T &t) {//一元谓词
		return (t%divisor) == 0;
	}
private:
	T divisor;
};

//一元谓词
void test_3() {
	vector<int> v2;
	for (int i = 10; i < 33; i++) {
		v2.push_back(i);
	}

	int a = 4;
	IsDiv<int> myDiv(a);

	vector<int>::iterator it;
	it = find_if(v2.begin(), v2.end(), IsDiv<int>(a));
	if (it == v2.end()) {
		cout << "no element could be divisor by 4" << endl;
	}
	else {
		cout << "the first element divisor by 4 is:" << *it << endl;
	}
}

//二元谓词
template<typename T>
class SumAdd {
public:
	T operator() (T t1, T t2) {//仿函数
		return t1 + t2;
	}
};

void test_4() {
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	/*
	template<class _InIt1,
		class _InIt2,
		class _OutIt,
		class _Fn> inline
		_OutIt transform(const _InIt1 _First1, const _InIt1 _Last1,
			const _InIt2 _First2, _OutIt _Dest, _Fn _Func)*/
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//普通函数
bool MyCompare(const int &a, const int &b) {
	return a < b;//从小到大
}

void test_5() {
	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 100;
		v[i] = tmp;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	for_each(v.begin(), v.end(), FuncShowElemt2);
	cout << endl;

	sort(v.begin(), v.end(), MyCompare);
	for_each(v.begin(), v.end(), FuncShowElemt2);
	cout << endl;
}

struct CompareNoCase {
public:
	constexpr bool operator()(const string &str1, const string &str2) {
		string str1_, str2_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);//tolower, 预定义函数

		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);//tolower, 预定义函数

		return (str1_ < str2_);//从小到大
	}
};

void test_6() {
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");

	set<string>::iterator it = set1.find("aAa");//by default, case sensitive
	if (it != set1.end()) {
		cout << "find out aaa" << endl;
	}
	else {
		cout << "no aaa" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it2 = set2.find("aAa");//case unsensitive
	//if (it2 != set2.end()) {
	//	cout << "find out aAa" << endl;
	//}
	//else {
	//	cout << "no aAa" << endl;
	//}
}

int main() {
	//test_1();//函数对象的基本概念
	//test_2();//函数对象的优点/ 函数对象做: 1.函数参数/ 2.返回值
	//test_3();//一元谓词
	//test_4();//二元函数对象 和 二元谓词
	//test_5();//二元函数对象 和 二元谓词
	test_6();//二元谓词 在set集合中的应用

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
