#include "stdafx.h"
#include <iostream>

using namespace std;

class MyArray {
public:
	MyArray(int len);
	~MyArray();
public:
	int getLen();
	int &operator[](int index);

	class eSize {
	public:
		eSize(int size) {
			this->m_size = size;
		}
		virtual void printErr() {
			cout << "size: " << m_size << endl;
		}
	protected:
		int m_size;
	};
	class eNegative :public eSize {
	public:
		eNegative(int size) : eSize(size) {}
		virtual void printErr() {
			cout << "eNegative err size: " << m_size << endl;
		}
	};
	class eZero :public eSize {
	public:
		eZero(int size) : eSize(size) {}
		virtual void printErr() {
			cout << "eZero err size: " << m_size << endl;
		}
	};
	class eTooBig :public eSize {
	public:
		eTooBig(int size) : eSize(size) {}
		virtual void printErr() {
			cout << "eTooBig err size: " << m_size << endl;
		}
	};
	class eTooSmall :public eSize {
	public:
		eTooSmall(int size) : eSize(size) {}
		virtual void printErr() {
			cout << "eTooSmall err size: " << m_size << endl;
		}
	};
private:
	int *m_space;
	int m_len;
};

// 构造函数没有返回值, 要采用异常机制
MyArray::MyArray(int len) {
	if (len < 0) {
		throw eNegative(len);
	}
	else if (len == 0) {
		throw eZero(len);
	}
	else if (len > 1000) {
		throw eTooBig(len);
	}
	else if (len < 3) {
		throw eTooSmall(len);
	}
	this->m_len = len;
	this->m_space = new int[this->m_len];
}

MyArray::~MyArray() {
	if (this->m_space != NULL)
	{
		delete this->m_space;
		this->m_space = NULL;
		this->m_len = 0;
	}
}

int MyArray::getLen() {
	return this->m_len;
}
int &MyArray::operator[](int index) {
	return m_space[index];
}

int main() {
	try {
		//MyArray arr(-5);
		MyArray arr(2000);
		for (int i = 0; i < arr.getLen(); i++)
		{
			arr[i] = i + 1;
			cout << "%d " << arr[i];
		}
		cout << endl;
	}
	catch (MyArray::eSize &e) {
		e.printErr();
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
