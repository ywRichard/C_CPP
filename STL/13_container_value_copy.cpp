#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/*
	All the containers just implement the "value copy" otherthan "reference copy"
	全部容器只能提供 值 语意, 而不是 引用 语意
	要在STL容器中存储带有指针成员的元素, 有 深copy 和 浅copy
	需要重载 =号操作符 和 copy构造函数
*/
class Teacher {
public:
	Teacher(const char* name, int age) {
		m_pname = new char[strlen(name) + 1];
		m_age = age;
	}
	~Teacher() {
		if (m_pname != NULL) {
			delete m_pname;
			m_pname = NULL;
			m_age = 0;
		}
	}
	//Teacher t2=t1;
	Teacher(const Teacher &obj) {
		this->m_pname = new char[strlen(obj.m_pname) + 1];
		strcpy_s(this->m_pname, strlen(obj.m_pname) + 1, obj.m_pname);
		this->m_age = obj.m_age;
	}
public:
	//t3=t2=t1
	Teacher & operator=(Teacher &obj) {
		//delete old memory
		if (m_pname != NULL) {
			delete m_pname;
			m_pname = NULL;
			m_age = 0;
		}

		//allocate new memory
		m_pname = new char[strlen(obj.m_pname) + 1];

		//deep copy value
		strcpy_s(m_pname, strlen(obj.m_pname) + 1, obj.m_pname);
		m_age = obj.m_age;

		return *this;
	}
	void printT() {
		cout << m_pname << ": " << m_age << endl;
	}
private:
	char* m_pname;
	int m_age;
};

int main() {
	Teacher t1("t1", 31);
	t1.printT();

	vector<Teacher> v1;
	//把t1拷贝一份, 存入容器中...
	v1.push_back(t1);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}