#include "stdafx.h"
#include <iostream>
#include <iomanip>//IO 操作符

using namespace std;

int main() {
	cout << "hello" << endl;
	cout.put('h').put('e').put('l') << endl;//put 输出单个字符
	const char *p = "hello world";

	int len = strlen(p);
	cout.write(p, len) << endl;
	cout.write(p, len - 4) << endl;
	cout.write(p, len + 4) << endl;

	//使用类成员函数
	cout << "<start>" << endl;
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);//显示基准
	//cout.setf(ios::internal);//设置
	cout << hex << 123 << "<End>" << endl;

	cout << endl;

	cout << "<start>"
		<< setw(30)
		<< setfill('*')
		//<< setiosflags(ios::showbase)
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<End>" << endl;
	

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
