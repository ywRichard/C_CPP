#include "stdafx.h"
#include <iostream>
#include "24_MyVector.cpp"

using namespace std;

/********************************************
1.在模板数组类, 储存int
********************************************/
int main01() {
	MyVector<int> myv1(10);
	for (int i = 0; i < myv1.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv1[i] << " ";
	}
	cout << endl;

	MyVector<int> myv2 = myv1;
	for (int i = 0; i < myv2.getLen(); i++)
	{
		cout << myv2[i] << " ";
	}

	cout << myv2 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

/********************************************
2.在模板数组类, 储存char
********************************************/
int main02() {
	MyVector<char> myv1(10);
	int num = (int)'a';
	for (int i = 0; i < 10; i++)
	{
		myv1[i] = (char)i + num;
	}

	cout << myv1 << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
/********************************************
3.在模板数组类, 储存Teachr
********************************************/

class Teacher {
public:
	Teacher() {
		age = 33;
		strcpy_s(name, "");
	}
	Teacher(const char *name, int age) {
		this->age = age;
		strcpy_s(this->name, name);
	}
	void printT() {
		cout << name << ", " << age << endl;
	}
private:
	int age;
	char name[32];
};

int main03() {
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);
	MyVector<Teacher> tArray(4);

	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;

	Teacher tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp = tArray[i];
		tmp.printT();
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}


/*********************************************
4.作业, 优化teacher类,
	1.属性变成 char *pName, 在构造函数里面分配内存
	2.析构函数 释放pName指向的内存空间
	3.避免浅拷贝 重载=, 重写拷贝构造函数
	4.重载<<
	5.在模板数组类, 储存int, char, Teachr, *Teacher
*********************************************/

class AdvTeacher {
	//<<
	friend ostream& operator<<(ostream &out, AdvTeacher &obj);
public:
	AdvTeacher() {
		this->age = 0;
		this->m_len = 0;
		this->pName = new char[m_len + 1];
		strcpy_s(this->pName, this->m_len+1, "");
	}
	AdvTeacher(const char *name, int age) {
		this->age = age;

		m_len = strlen(name);
		pName = new char[m_len + 1];
		strcpy_s(this->pName, m_len + 1, name);
	}
	AdvTeacher(const AdvTeacher &obj) {
		this->age = obj.age;

		this->m_len = obj.m_len;
		this->pName = new char[this->m_len + 1];
		strcpy_s(this->pName, this->m_len + 1, obj.pName);
	}
	~AdvTeacher() {
		if (this->pName != NULL) {
			delete[] this->pName;
			this->m_len = 0;
			this->pName = NULL;
		}
	}
public:
	void printT() {
		cout << "name: " << this->pName << ";age: " << this->age << endl;
	}
	//t1=t2=t3
	AdvTeacher &operator=(AdvTeacher &obj) {
		if (this->pName != NULL) {
			delete[] this->pName;
			this->m_len = 0;
			this->pName = NULL;
		}
		this->age = obj.age;
		this->m_len = obj.m_len;
		this->pName = new char[this->m_len + 1];
		strcpy_s(this->pName, m_len + 1, obj.pName);

		return *this;
	}
private:
	int age;
	char *pName;
	int m_len;
};

ostream& operator<<(ostream &out, AdvTeacher &obj) {
	out << "name: " << obj.pName << endl;
	return out;
}

int main04() {
	AdvTeacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);
	MyVector<AdvTeacher> tArray(4);

	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;

	AdvTeacher tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp = tArray[i];
		tmp.printT();
	}

	cout << tArray << endl;

	AdvTeacher t5 = t4;
	t5.printT();

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

/********************************************
5.在模板数组类, *Teacher
********************************************/
int main() {
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);
	MyVector<Teacher*> tArray(4);

	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;

	Teacher *tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp = tArray[i];
		tmp->printT();
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}