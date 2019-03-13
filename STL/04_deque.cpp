#include "stdafx.h"
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printD(deque<int> &d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
}

//
void test_1() {
	deque<int> d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(5);
	d.push_back(-11);
	d.push_back(-22);
	d.push_back(-33);
	printD(d);

	cout << "head element:" << d.front() << endl;
	cout << "end element:" << d.back() << endl;
	printD(d);

	d.pop_front();
	d.pop_back();
	printD(d);
}

void test_2() {
	deque<int> d;
	d.push_back(1);
	d.push_back(3);
	d.push_back(5);
	d.push_back(-11);
	d.push_back(-22);
	d.push_back(-33);

	//find array subscript
	deque<int>::iterator it = find(d.begin(), d.end(), -33);
	if (it != d.end()) {
		cout << "-33 array subscript:" << distance(d.begin(), it) << endl;
	}
	else {
		cout << "no element of value is 33" << endl;
	}
}

int main() {
	test_1();
	//test_2();
	cout << "hello..." << endl;
	system("pause");
	return 0;
}
