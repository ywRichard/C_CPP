#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

/*
	cin.get()//一次只能读取一个字符
	cin.get(a)//读取一个字符
	cin.get(a,b)//可以读字符串
	cin.getline()
	cin.ignore()
	cin.peek()
	cin.putback()
*/
int main01() {
	char mybuf[1024];
	int myint;
	long mylong;

	cin >> myint;
	cin >> mylong;
	cin >> mybuf;//遇到空格就停止接受, aa bb==> aa

	cout << "myint: " << myint << endl;
	cout << "mylong: " << mylong << endl;
	cout << "mybuf: " << mybuf << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

int main02() {
	char ch;
	//一次只能读取一个字符
	while ((ch=cin.get())!=EOF)
	{
		cout << ch << endl;
	}
	system("pause");
	return 0;
}

int main03() {
	cout << "cin.get(a), the process will be stuck if there is no data in buffer" << endl;
	char a, b, c;
	cin.get(a).get(b).get(c);//空格也算一个字符

	cout << a << b << c<<endl;

	system("pause");
	return 0;
}

int main04() {
	char buf1[256];
	char buf2[256];
	cout << "test string: aa bb cc dd" << endl;

	cin >> buf1;
	cin.ignore(2);//==skip()
	int num = cin.peek();
	cin.getline(buf2, 256);
	cout << "buf1: " << buf1 << endl;//aa
	cout << "buf2: " << buf2 << endl;//b cc dd

	cout << "num1: " << num << endl;
	num = cin.peek();//如果buf为空，就将线程挂起，等待buf有输入之后再执行。类似异步编程
	cout << "num2: " << num << endl;

	system("pause");
	return 0;
}

int main() {
	cout << "input: a number or a word" << endl;
	char c = cin.get();

	if ((c>='0')&&(c<='9')){//分别处理整数和字符串
		int n;
		cin.putback(c);//putback the character we are handled to stream
		cin >> n;
		cout << "The number you entered:" << n << endl;
	}
	else{
		string str;
		cin.putback(c);
		getline(cin, str);
		cout << "The string you entered:" << str << endl;
	}

	system("pause");
	return 0;
}