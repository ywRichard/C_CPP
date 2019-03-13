#include "stdafx.h"
#include "iostream"

using namespace std;

//function pointer syntax
//1.a "function data type" declaration
//void myfunc(int a, int b)
typedef void (myTypeFunc)(int a, int b);//declare a customzied data type, similar with above function declaration.
//myTypeFunc *myfuncp = NULL;//define a function pointer, it points the primary address of the function. 

//2."function pointer data type" declaration
typedef void(*myPTypeFunc)(int a, int b);//declare a customzied function pointer data type
//myPTypeFunc fp = NULL;//define a function pointer

//3.a "function pointer variable" defination
void(*myVarPFunc)(int a, int b);

void myfunc(int a) {
	printf("a:%d \n", a);
}

void myfunc(char *p) {
	printf("p:%s \n", p);
}

void myfunc(int a, int b) {
	printf("a:%d, b:%d \n", a, b);
}

int main05() {
	//myTypeFunc *myfuncp = NULL;//define a function pointer, it points the primary address of the function. 
	myPTypeFunc fp = NULL;
	fp = myfunc;

	fp(1, 2);
	//fp(1);

	return 0;
}