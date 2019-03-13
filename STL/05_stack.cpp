#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//stack model --> FILO
//stack algorithm & data type
void test_1() {
	stack<int> s;

	//push stack
	for (int i = 0; i < 10; i++) {
		s.push(i + 1);
	}
	cout << "stack size:" << s.size() << endl;

	//pop stack
	while (!s.empty()) {
		int tmp = s.top();//get top element in stack 
		cout << tmp << " ";
		s.pop();//pop top element
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

//manuplate element
void test_2() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	stack<Teacher> s;//编译器将元素copy到容器中, 所以元素要可以copy, 并且要注意 deep copy和swallow copy的问题
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty()) {
		Teacher tmp = s.top();
		tmp.printT();
		s.pop();
	}
}

//store pointer
void test_3() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	stack<Teacher*> s;//编译器将元素copy到容器中, 所以元素要可以copy, 并且要注意 deep copy和swallow copy的问题
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty()) {
		Teacher *tmp = s.top();
		tmp->printT();
		s.pop();
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
