#include "stdafx.h"
#include <iostream>

using namespace std;


/*============================*/
/*1.universal error checking*/
int myStrcpy01(char *to, char *from) {
	if (from == NULL)
		return 1;
	if (to == NULL)
		return 2;

	//check copy
	if (*from == 'a')
		return 3;
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

	return 0;
}
int main01() {
	int ret = 0;
	char src[] = "zbcdefg";
	char des[1024] = { 0 };
	//memset(des, 0, sizeof(des));
	ret = myStrcpy01(des, src);
	if (ret != 0)
	{
		switch (ret)
		{
		case 1:
			cout << "src error" << endl;
			break;
		case 2:
			cout << "des error" << endl;
			break;
		case 3:
			cout << "copy error" << endl;
			break;
		default:
			cout << "unknown error" << endl;
			break;
		}
	}
	cout << "des:" << des << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}


/*============================*/
/*2.throw int & throw char* */
void myStrcpy02(char *to, char *from) {
	if (from == NULL)
		throw 1;
	if (to == NULL)
		throw 2;

	//check copy
	if (*from == 'a')
		throw 3;

	if (*from == 'b')
		throw "copy error";
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}
int main02() {
	int ret = 0;
	//char src[] = "abcdefg";
	char src[] = "bbcdefg";
	char des[1024] = { 0 };
	//memset(des, 0, sizeof(des));
	
	try{
		myStrcpy02(des, src);
	}
	catch (int e){//catch(int) e is optional
		cout << "int error:" << e << endl;
	}
	catch (const char *e) {
		cout << "char *error:" << e << endl;
	}
	catch (...) {
		cout << "unknow exception" << endl;
	}
	cout << "des:" << des << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}


/*===================================*/
/*3.throw customized exception class */
//重点 ---> 自定义异常的 生命周期 和 内存分配
class mySrcError {};
class myDesError {};
class myCopyError {
public:
	myCopyError() {
		cout << "myCopyError() run" << endl;
	}
	myCopyError(const myCopyError &obj) {
		cout << "myCopyError(const myCopyError &obj) run" << endl;
	}
	~myCopyError()
	{
		cout << "~myCopyError() run" << endl;
	}
};
void myStrcpy03(char *to, char *from) {
	if (from == NULL)
		throw mySrcError();
	if (to == NULL)
		throw myDesError();

	//check copy
	if (*from == 'a') // test element & reference
		throw myCopyError();//会不会产生一个匿名对象?

	if (*from == 'b') 
		throw &(myCopyError());//-> wild pointer

	if (*from == 'c')
		throw new myCopyError;//->memory leak
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

int main() {
	int ret = 0;
	//char src[] = "abcdefg";
	//char src[] = "bbcdefg";
	char src[] = "cbcdefg";
	char des[1024] = { 0 };
	//memset(des, 0, sizeof(des));

	try {
		myStrcpy03(des, src);
	}
	catch (mySrcError e) {
		cout << "exceptiop of mySrcError"<< endl;
	}
	catch (myDesError e) {
		cout << "exceptiop of myDesError"<< endl;
	}
	//copy匿名对象 or 直接使用匿名对象
	/*	//结论1: element --> 调用copy构造函数, copy 匿名对象
		catch (myCopyError e) {
			cout << "exceptiop of myCopyError"<< endl;
		}
	*/

	/*	//结论2: reference --> 直接使用匿名对象
		catch (myCopyError &e) {//
			cout << "exceptiop of &myCopyError" << endl;
		}
	*/

	/*	//结论3: 指针可以和引用 & 元素写在一起; 
				 引用和元素不能写在一起
		catch (myCopyError *e) {//
			cout << "exceptiop of *myCopyError" << endl;
		}
	*/

	//结论4: 用类对象处理异常时，使用引用比较合适
	catch (myCopyError *e) {
		cout << "exceptiop of *myCopyError" << endl;
		delete e;
	}

	cout << "des:" << des << endl;

	cout << "hello..." << endl;
	system("pause");
	return 0;
}
