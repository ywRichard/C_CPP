#include "stdafx.h"
#include <iostream>

using namespace std;
/*
	c风格的强制类型转换(type cast), 适用于所有类型
	TYPE b = (type) a

	c++风格的类型转换, 有4中分别对应不同的场合
		1.static_cast: 静态类型转换, int -> char. 只适用于 基础类型, 不能用于 指针和类 等复杂数据类型
		2.reinterpreter_cast: 重新解释类型
		3.dynamic_cast: 动态类型转换, 用于子类和父类之间多态类型的转换
		4.const_cast: 去const属性
*/

class Animal {
public:
	virtual void cry() = 0;
};

class Dog :public Animal {
public:
	virtual void cry() {
		cout << "dog cry" << endl;
	}
	void doHome() {
		cout << "dog do home" << endl;
	}
};

class Cat :public Animal {
public:
	virtual void cry() {
		cout << "Cat cry" << endl;
	};

	void doThing() {
		cout << "cat doThing" << endl;
	}
};

class Tree {

};

//1. static_cast, 2.reinterpreter_cast
int main01() {

	double pi = 3.1415926;
	int num1 = (int)pi;// c style
	int num2 = static_cast<int>(pi);//c++ style, 编译时编译器会进行类型检查
	int num3 = pi;//c中 可发生隐式类型转换 均可使用 static_case<>() 替换

	//char* --> int*
	char *p1 = (char*)("this is *p1");
	//char *p1 = reinterpret_cast<char*>("this is *p1");
	int *p2 = NULL;
	p2 = reinterpret_cast<int*>(p1);//在不同类型之间, 进行强制类型转换
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;//012B8B30, 输出的是指针地址 相当于%d
	//总结: 通过 reinterpreter_cast<>() 和 static_cast<>() 把c语言的强制类型转换 都覆盖了...

	Animal *pBase = NULL;
	Dog d1;
	pBase = &d1;
	pBase = static_cast<Animal*>(&d1);//在编译时，编译器会进行类型检查
	pBase = reinterpret_cast<Animal*>(&d1);//强制类型转换
	{
		Tree t1;
		pBase = reinterpret_cast<Animal*>(&t1);
	}

	cout << "hello..." << endl;
	system("pause");
	return 0;
}

//3. dynamic_cast
void playObj(Animal *base) {
	base->cry();//polymorphism ->1.继承 2.virtual重写 3.父类调用子类对象
	//能识别子类对象
	//dynamic_cast, runtime类型识别
	Dog *pDog = dynamic_cast<Dog*>(base);
	if (pDog != NULL) {
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat*>(base);
	if (pCat!=NULL)
	{
		pCat->doThing();
	}
}

int main02() {
	Dog d1;
	Cat c1;

	playObj(&d1);
	playObj(&c1);

	cout << "hello world" << endl;
	system("pause");
	return 0;
}

//4. const_cast 
void printfBuf(const char* p) {
	char *p1 = NULL;
	//要清楚的知道 变量: 转换之前的类型, 转换之后的类型
	//const char* ---> char * 把只读属性 去掉
	p1 = const_cast<char*>(p);
	
	p1[0] = 'A';//通过p1 去修改内存空间
	cout << p << endl;
}
int main() {
	char buf[] = "bbbbbb";
	printfBuf(buf);

	//要确保 p所指向的内存空间 确实能修改; 如果不能修改会造成core down
	const char *myp = "qqqqqqq";//pointer指向的变量没有在栈上分配内存
	printfBuf(myp);
	cout << "hello world" << endl;
	system("pause");
	return 0;
}