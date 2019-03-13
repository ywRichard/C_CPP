#include "stdafx.h"
#include <iostream>

using namespace std;
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>


void printList(list<int> &l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void printV(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void showElem(int &n) {
	cout << n << " ";
}

class CMyShow {
public:
	CMyShow() {
		num = 0;
	}
	void operator()(int &n) {
		num++;
		cout << n << " ";
	}
	void printNum() {
		cout << "num:" << num << endl;
	}
private:
	int num;
};

//foreach
void test_1() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	//函数对象, 回调函数入口地址
	for_each(v1.begin(), v1.end(), showElem);
	cout << endl;

	for_each(v1.begin(), v1.end(), CMyShow());//匿名的函数对象
	cout << endl;
}

int increase(int i) {
	return i + 100;
}

//transform
void test_2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	transform(v1.begin(), v1.end(), v1.begin(), increase);
	printV(v1);

	/*
	template<class _Ty = void>
	struct negate
	{	// functor for unary operator-
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty argument_type;
	_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty result_type;

	constexpr _Ty operator()(const _Ty& _Left) const
		{	// apply operator- to operand
		return (-_Left);
		}
	};*/
	//预定义的函数对象
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printV(v1);

	//函数适配器
	list<int> myList;
	myList.resize(v1.size());

	transform(v1.begin(), v1.end(), myList.begin(), bind2nd(multiplies<int>(), 10));
	cout << endl;

	//transform 直接把运算结果输出到屏幕
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
	cout << endl;
}

int showElem2(int n) {
	cout << n << " ";
	return n;
}

void test_3() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	for_each(v1.begin(), v1.end(), showElem);
	cout << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(5);

	/*// FUNCTION TEMPLATE transform
	template<class _InIt,
		class _OutIt,
		class _Fn> inline
		_OutIt transform(const _InIt _First, const _InIt _Last, _OutIt _Dest, _Fn _Func)
		{	// transform [_First, _Last) with _Func
		_DEPRECATE_UNCHECKED(transform, _Dest);
		_DEBUG_RANGE(_First, _Last);
		auto _UFirst = _Unchecked(_First);
		const auto _ULast = _Unchecked(_Last);
		auto _UDest = _Unchecked_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
		for (; _UFirst != _ULast; ++_UFirst, (void)++_UDest)
			{
			*_UDest = _Func(*_UFirst);
			}

		return (_Rechecked(_Dest, _UDest));
	}*/

	//一般情况下: for_each所使用的函数对象, 参数是应用, 没有返回值
	//transform所使用的函数对象, 参数一般不使用引用, 而是还有返回值
	transform(v2.begin(), v2.end(), v2.begin(), showElem2);
	cout << endl;
}

//adjacent_filed
void test_4() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end()) {
		cout << "no repetitive data" << endl;
	}
	else {
		cout << "the repetitive item:" << *it << endl;
	}
}

//binary_search
void test_5() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool b = binary_search(v1.begin(), v1.end(), 7);
	if (b == true) {
		cout << "find it" << endl;
	}
	else {
		cout << "no finding" << endl;
	}
}

//element count, not just for basic data type
bool GreaterThree(int iNum) {
	return (iNum > 3);
}
void test_6() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	int num = count(v1.begin(), v1.end(), 7);
	cout << "element=7 count:" << num << endl;

	num = count_if(v1.begin(), v1.end(), GreaterThree);
	cout << "element>3 count_if:" << num << endl;
}

//find/ find_if
void test_7() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(7);

	vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
	cout << "*it" << *it << endl;

	//第一个大于3的位置
	vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), GreaterThree);
	cout << "*it2" << *it2 << endl;
}

//merge
void test_8() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	//merge的时候, 子容器的元素 顺序要从小到大;  插入后会排序
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}

class Student {
public:
	Student(string name, int id) {
		this->m_name = name;
		this->m_id = id;
	}
	void printT() {
		cout << "name:" << m_name << " " << "id:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};
bool CompareS(Student &s1, Student &s2) {
	return (s1.m_id < s2.m_id);
}
//sort
void test_9() {
	Student s1("boss_1", 1);
	Student s2("boss_2", 2);
	Student s3("boss_3", 3);
	Student s4("boss_4", 4);
	vector<Student> v1;
	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s2);

	for (vector<Student>::iterator it = v1.begin(); it != v1.end(); it++) {
		it->printT();
	}

	//sort 通过 自定义的函数对象 实现排序算法
	//算法的统一性 ===> 技术手段, 函数对象
	sort(v1.begin(), v1.end(), CompareS);
	cout << "sort:" << endl;
	for (vector<Student>::iterator it = v1.begin(); it != v1.end(); it++) {
		it->printT();
	}
}

//random_shuffle
void test_10() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	random_shuffle(v1.begin(), v1.end());
	printV(v1);

	string str = "abcdefg";
	random_shuffle(str.begin(), str.end());
	cout << "str:" << str << endl;
}

//reverse
void test_11() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	reverse(v1.begin(), v1.end());

	printV(v1);
}

//copy
void test_12() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	printV(v2);
}

bool great_equal(int &n) {
	return n >= 5;
}
//replace/ replace_if
void test_13() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(3);
	replace(v1.begin(), v1.end(), 3, 8);

	//>5
	replace_if(v1.begin(), v1.end(), great_equal, 7);

	printV(v1);
}

//swap
void test_14() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	swap(v1, v2);
	printV(v1);
}

//accumulate
void test_15() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	
	int tmp = accumulate(v1.begin(), v1.end(), 100);
	cout << tmp << endl;
}

//fill
void test_16() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	fill(v1.begin(), v1.end(), 8);
	printV(v1);
}

//union
void test_17() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(5);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}
int main() {
	//test_1();//for_each

	//test_2();//transform

	//test_3();//transform vs for_each

	//test_4();//adjacent_filed

	//test_5();//binary_search

	//test_6();//count/ count_if, not just for basic data type

	//test_7();//find/ find_if

	//test_8();//merge

	//test_9();//sort

	//test_10();//random_shuffle

	//test_11();//reverse

	//test_12();//copy

	//test_13();//replace/ replace_if

	//test_14();//swap

	//test_15();//accumalte

	//test_16();//fill

	test_17();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
