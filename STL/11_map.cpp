#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

//map --> 键值对集合
//add/traverse/delete
void test_1() {
	map<int, string> map1;

	//add
	//1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	//traverse
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
	cout << "traverse done" << endl;

	//delete
	cout << "begin delete" << endl;
	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << ": " << it->second << endl;
		map1.erase(it);
	}
}

//插入元素的四种方法的区别
//前三种, return pair<iterator, bool>, 若key存在, 插入失败 return false
//方法四, 若key存在, 修改key的value
void test_2() {
	map<int, string> map1;


	//return using _Pairib = pair<iterator, bool>;
	pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//2
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//3
	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(5, "teacher05"));
	if (mypair5.second != true) {
		cout << "<5, teacher5> insert failed" << endl;
	}
	else {
		cout << "<5, teacher5> insert done" << endl;
	}
	pair<map<int, string>::iterator, bool> mypair6 = map1.insert(map<int, string>::value_type(5, "teacher55"));
	if (mypair6.second != true) {
		cout << "<5, teacher55> insert failed" << endl;
	}
	else {
		cout << "<5, teacher55> insert done" << endl;
	}

	//4
	map1[7] = "teacher07";
	map1[7] = "teacher77";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
	cout << "traverse done" << endl;
}

//map 查找, 异常处理
void test_3() {
	map<int, string> map1;

	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	map<int, string>::iterator it = map1.find(100);
	if (it == map1.end()) {
		cout << "key 100 no exitstance" << endl;
	}
	else {
		cout << it->first << ": " << it->second << endl;
	}

	//return pair<iterator, iterator>
	pair<map<int,string>::iterator,map<int,string>::iterator> mypair = map1.equal_range(5);
	//first iterator >= 5
	//second iterator > 5

	if (mypair.first==map1.end()) {
		cout << "first iterator >= 5 no existance" << endl;
	}
	else {
		cout << mypair.first->first << ": " << mypair.first->second << endl;
	}

	if (mypair.second == map1.end()) {
		cout << "second iterator >= 5 no existance" << endl;
	}
	else {
		cout << mypair.second->first << ": " << mypair.second->second << endl;
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
