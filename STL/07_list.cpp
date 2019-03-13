#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

void printL(list<int> &l) {
	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//basic operation
void test_1() {
	list<int> l;
	cout << "list size:" << l.size() << endl;
	for (int i = 0; i < 10; i++) {
		l.push_back(i + 1);
	}
	cout << "list size:" << l.size() << endl;
	printL(l);

	//list不能被随机访问
	list<int>::iterator it = l.begin();
	for (int i = 0; i < 3; i++) {
		it++;
	}
	//不支持随机访问容器
	//it = it + 5;//err, no operator "+" matches these operands
	l.insert(it, 100);//1 2 100 3 4...10
	printL(l);
	//结论1: 链表的index从0开始; insert元素, 在指定的位置插入新元素后, 该位置的元素都会先后移动
}

//delete
void test_2() {
	list<int> l;
	cout << "list size:" << l.size() << endl;
	for (int i = 0; i < 10; i++) {
		l.push_back(i + 1);
	}
	cout << "list size:" << l.size() << endl;
	printL(l);//1 2 3 4...10

	//list不能被随机访问
	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	for (int i = 0; i <= 3; i++) {
		it2++;
	}

	l.erase(it1, it2);
	printL(l);//5 6 7....10

	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	printL(l);//100 100 100 5 6 7....10

	l.erase(l.begin());//remove 1x 100
	l.remove(100);//remove 2x 100
	printL(l);
}


int main() {
	//test_1();
	test_2();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
