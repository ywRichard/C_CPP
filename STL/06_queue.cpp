#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

//queuw --> FIFO
//basic data type
void test_1() {
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);

	cout << "queue head:" << q.front() << endl;
	cout << "queue size:" << q.size() << endl;
	while (!q.empty()) {
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
	}
	cout << endl;
}
class Teacher {
public:
	int age;
	char name[32];
public:
	void printT() {
		cout << "age:" << age << endl;
	}
};

//element
void test_2() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);

	while (!q.empty()) {
		Teacher tmp = q.front();
		tmp.printT();
		q.pop();
	}
}

//pointer
void test_3() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while (!q.empty()) {
		Teacher *tmp = q.front();
		tmp->printT();
		q.pop();
	}
}

int main() {
	//test_1();
	//test_2();
	test_3();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
