#include "stdafx.h"
#include <iostream>
#include "string"
#include "algorithm"

using namespace std;

//initialize string
void test_1() {
	string s1 = "aaaa";
	string s2("bbb");
	string s3 = s2;//copy sonstruct
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}

//traverse string
void test_2() {
	string s1 = "abcdefg";

	//array
	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}

	//iterator
	for (string::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//s1.at --> throw exception
	try
	{
		for (int i = 0; i < s1.length() + 3; i++)
		{
			cout << s1.at(i) << " ";
		}
		cout << endl;
	}
	catch (...)
	{
		cout << "throw exception from s1.at(i)" << endl;
	}

	try
	{
		for (int i = 0; i < s1.length() + 3; i++)
		{
			cout << s1[i] << " ";//不会抛异常
		}
	}
	catch (const std::exception&)
	{
		cout << "exception" << endl;
	}
}

//char* <===> string
void test_3() {
	//1.char* --> string
	string s1 = "aaabbb";

	//2.string --> char*
	const char *p = s1.c_str();
	cout << p << endl;

	//3.string copy char[]
	//char buf[128];
	char buf[128] = { 0 };
	//s1.copy(buf, 3, 0); // unsafe error

	cout << "buf:" << buf << endl;
}

//combine string
void test_4() {
	string s1 = "aaa";
	string s2 = "bbb";
	s1 = s1 + s2;
	cout << "s1:" << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3:" << s3 << endl;
}

// find & replace
void test_5() {
	string s1 = "qwe hello qwe 123 qwe 456 qwe 789";
	int index = s1.find("qwe", 0);
	cout << "index:" << index << endl;

	//qwe出现的次数 每一个下标
	int offindex = s1.find("qwe", 0);
	while (offindex != string::npos)
	{
		cout << "offindex:" << offindex << endl;
		s1.replace(offindex, 3, "WBM");
		offindex = s1.find("qwe", offindex + 1);
	}

	cout << "replace result of s1:" << s1 << endl;
}

//truncate & delete
void test_6() {
	string s1 = "hello1 hello2 hello3";
	string::iterator it = find(s1.begin(), s1.end(), '1');
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << "s1 delete 1:" << s1 << endl;

	//truncate
	s1.erase(s1.begin(), s1.end());
	cout << "delete all s1:" << s1 << endl;
	cout << "s1 length:" << s1.length() << endl;

	string s2 = "BBB";
	s2.insert(0, "AAA");//insert from head
	cout << s2 << endl;

	s2.insert(s2.length(), "ccc");//append string
	cout << s2 << endl;
}

// string tranform
void test_7() {
	string s1 = "AAAbbb";
	//1.func entry, 2.func obj, 3.predefine func obj
	transform(s1.begin(), s1.end(), s1.begin(), toupper);
	cout << "s1:" << s1 << endl;

	string s2 = "CCCddd";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	cout << "s2:" << s2 << endl;
}

int main02() {
	//test_1();
	//test_2();
	//test_3();
	//test_4();
	//test_5();
	//test_6();
	test_7();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
