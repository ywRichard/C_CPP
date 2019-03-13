#include "stdafx.h"
#include <iostream>
#include "vector"

using namespace std;

void printV(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

//add & delete element
void test_1() {
	vector<int> v1;

	cout << "length:" << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout << "length:" << v1.size() << endl;
	cout << "top element:" << v1.front() << endl;

	while (v1.size() > 0) {
		cout << "bottom element:" << v1.back() << endl;;
		v1.pop_back();//remove bottom element
	}
}

//initialize vector
void test_2() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;//copy construct
	vector<int> v3(v1.begin(), v1.begin() + 2);//1 3
	cout << "v1:";
	printV(v1);

	cout << "v2:";
	printV(v2);

	cout << "v3:";
	printV(v3);
}

//traverse vector
void test_3() {
	vector<int> v1(10);

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	printV(v1);
}

//push_back
void test_4() {
	vector<int> v1(3);//*allocate memory
	v1.push_back(100);
	v1.push_back(200);
	cout << "size:" << v1.size() << endl;
	printV(v1);//0 0 0 100 200
}

//the kinds of iterator
void test_5() {
	vector<int> v1(10);

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	cout << "forward:";
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "reverse:";
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++) {
		cout << *rit << " ";
	}
	cout << endl;
}

//delete
void test_6() {
	vector<int> v1(10);

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	//delete by range
	v1.erase(v1.begin(), v1.begin() + 3);
	printV(v1);

	//delete by element pos
	v1.erase(v1.begin());// delete the top element

	//delete by element value
	v1[1] = 2;
	v1[3] = 2;
	printV(v1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end();) {
		if (*it == 2) {
			it = v1.erase(it);//当删除迭代器所指向的元素时, erase删除函数会让it自动下移
		}
		else {
			it++;
		}
	}
	printV(v1);
}

//insert element
void test_7() {
	vector<int> v1(10);

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	v1.insert(v1.begin(), 100);//insert head
	v1.insert(v1.end(), 200);//insert end

	printV(v1);
}

int main() {
	//test_1();//add & delete element
	//test_2();//initialize vector
	//test_3();//traverse vector
	//test_4();//push_back
	//test_5();//the kinds of iterator
	//test_6();//delete
	test_7();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
