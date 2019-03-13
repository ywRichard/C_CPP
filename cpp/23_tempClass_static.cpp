#include "stdafx.h"
#include <iostream>
//#include "23_AA.cpp"

using namespace std;

template<typename T>
class AA {
public:
	static T m_a;
};

//m_a 为每种类型创建一个类 并且使用自己类型的m_a
/*
原理, 模板的二次编译
编译器并不是将static, 模板编译成能够处理任意数据类型的类
而是通过具体类型产生不同的类
*/
template<typename T>
T AA<T>::m_a = 0;

/*//编译器会创建一下两个类
class AA1 {
public:
	static int m_a;
};

class AA2 {
public:
	static int m_a;
};
*/

int main() {
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;
	cout << AA<int>::m_a << endl;//12

	AA<char> b1, b2, b3;
	b1.m_a = 'a';
	b2.m_a++;
	b3.m_a++;
	cout << AA<char>::m_a << endl;//c

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
