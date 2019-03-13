#include "stdafx.h"
#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

//predefined function
void test_1() {
	//predefined function,
	//c++编译器 预定义的函数对象 实现了数据类型和算法的分离
	//怎么知道 plus<type> 是两的参数? ==> 直接看源码
	/*	template<class _Ty = void>
		struct plus
		{	// functor for operator+
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty result_type;

		constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
			{	// apply operator+ to operands
			return (_Left + _Right);
			}
		}; */
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y);
	cout << "z: " << endl;

	plus<string> stringAdd;
	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1, s2);
	cout << "s3: " << s3 << endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzz");

	sort(v1.begin(), v1.end(), greater<string>());
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}

	//function adaptor, 函数适配器
	//求 "ccc" 出现的个数
	v1.push_back("ccc");
	v1.push_back("ccc");
	string sc = "ccc";

	//equal_to<string>() 有两个参数 left参数来自容器, right来自sc
	//bind1st/ bind2nd 函数适配器
	int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
	cout << "num: " << num << endl;
}

//function adaptor
class IsGreat {
public:
	IsGreat(int i) {
		m_num = 1;
	}
	bool operator()(int &num) {
		if (num > m_num)
			return true;

		return false;
	}
private:
	int m_num;
};

void test_2() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int num1 = count(v.begin(), v.end(), 3);
	cout << "num1:" << num1 << endl;

	//通过 谓词 求>2 的个数
	int num2 = count_if(v.begin(), v.end(), IsGreat(3));
	cout << "num2:" << num2 << endl;

	//预定义的函数对象 求 大于2的个数
	/*
	template<class _Ty = void>
		struct greater
		{	// functor for operator>
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty first_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef _Ty second_argument_type;
		_CXX17_DEPRECATE_ADAPTOR_TYPEDEFS typedef bool result_type;

		constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
			{	// apply operator> to operands
			return (_Left > _Right);
			}
		};
	*/
	//greater<int>() 有两个参数, 左参数来自容器的元素, 有参数固定成2(通过bind2nd)
	int num3 = count_if(v.begin(), v.end(), bind2nd(greater<int>(), 2));
	cout << "num3:" << num3 << endl;

	//求奇数个数
	int num4 = count_if(v.begin(), v.end(), bind2nd(modulus<int>(), 2));
	cout << "odd num4:" << num4 << endl;

	//求偶数个数 取反器(negator)
	int num5 = count_if(v.begin(), v.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "even num5:" << num5 << endl;
}
int main() {
	//test_1();
	test_2();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
