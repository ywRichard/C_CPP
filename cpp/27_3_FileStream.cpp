#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main01() {
	const char *fname = "c:/Users/victor/desktop/1.txt";
	ofstream fout(fname, ios::app);
	if (!fout) {
		cout << "open file err" << endl;
		return 0;
	}

	fout << "hello....1111" << endl;
	fout << "hello....2222" << endl;
	fout << "hello....3333" << endl;
	fout.close();

	//读文件
	ifstream fin(fname);//建立一个输出流对象和文件关联
	char ch;
	while (fin.get(ch)) {
		cout << ch;
	}
	fin.close();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

class Animal{};
class Person :public Animal {};
class Teacher:public Person {
public:
	Teacher() {
		age = 10;
		strcpy_s(name, "");
	}
	Teacher(int age, const char *name) {
		this->age = age;
		strcpy_s(this->name, name);
	}
	void printT() {
		cout << "age: " << age << "name: " << name << endl;
	}
private:
	int age;
	char name[32];
};

int main() {
	const char *fname = "c:/Users/victor/desktop/1.dat";
	ofstream fout(fname, ios::binary);
	if (!fout) {
		cout << "open file err" << endl;
		return 0;
	}

	Teacher t1(31, "t31");
	Teacher t2(32, "t32");

	fout.write((char *)&t1, sizeof(t1));
	fout.write((char *)&t2, sizeof(t2));
	fout.close();

	ifstream fin(fname);
	Teacher tmp;

	fin.read((char*)&tmp, sizeof(tmp));
	tmp.printT();
	fin.read((char*)&tmp, sizeof(tmp));
	tmp.printT();

	cout << "done...." << endl;
	system("pause");
	return 0;
}
