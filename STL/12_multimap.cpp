#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
	string Name;
	int age;
	string tel;
	double saly;
};

void test_1() {
	Person p1, p2, p3, p4, p5;
	p1.Name = "wang 1";
	p1.age = 31;
	p2.Name = "li 2";
	p2.age = 32;
	p3.Name = "zhang 3";
	p3.age = 33;
	p4.Name = "qian 4";
	p4.age = 34;
	p5.Name = "zhao 5";
	p5.age = 35;

	multimap<string, Person> map1;
	//sales department
	map1.insert(make_pair("sales", p1));
	map1.insert(make_pair("sales", p2));

	//dev department
	map1.insert(make_pair("development", p3));
	map1.insert(make_pair("development", p4));

	//financial department
	map1.insert(make_pair("financial", p5));

	for (map<string, Person>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << ": " << it->second.Name << endl;
	}
	cout << "traverse done" << endl;

	int num = map1.count("development");
	cout << "dev employee number: " << num << endl;

	cout << "dev department employee information:" << endl;
	multimap<string, Person>::iterator it2 = map1.find("development");

	int tag = 0;
	while (it2 != map1.end() && tag < num) {
		cout << it2->first << ": " << it2->second.Name << endl;
		it2++;
		tag++;
	}
}

void test_2() {
	Person p1, p2, p3, p4, p5;
	p1.Name = "wang 1";
	p1.age = 31;
	p2.Name = "li 2";
	p2.age = 32;
	p3.Name = "zhang 3";
	p3.age = 33;
	p4.Name = "qian 4";
	p4.age = 34;
	p5.Name = "zhao 5";
	p5.age = 35;

	multimap<string, Person> map1;
	//sales department
	map1.insert(make_pair("sales", p1));
	map1.insert(make_pair("sales", p2));

	//dev department
	map1.insert(make_pair("development", p3));
	map1.insert(make_pair("development", p4));

	//financial department
	map1.insert(make_pair("financial", p5));

	cout << "filter data by condition to modify" << endl;
	for (multimap<string, Person>::iterator it = map1.begin(); it != map1.end(); it++){
		if (it->second.age==32){
			it->second.Name = "name32";
		}
	}

	for (multimap<string,Person>::iterator it = map1.begin(); it!=map1.end(); it++){
		cout << it->first << ": " << it->second.Name << endl;
	}
}

int main() {
	//test_1();
	test_2();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
