// 02_BitwiseOperator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main02()
{
	//int a = 0b11110000;
	//printf("Original value: %b\n", a);
	//################task 1##################
	//1. Implment kind of ways about Print integer in binary

	//2. Excise about bitwise operator, & | ^
	int a = 0xf0i16;//1111 0000
	int b = 0xaa;//1010 1010

	printf("a&b: %x\n", a&b);//1010 0000
	printf("a|b: %x\n", a | b);//1111 1010
	printf("a^b: %x\n", a^b);//0101 1010

	//3. shift bit << >>
	printf("a<<2: %x\n", a << 2);//
	printf("a>>2: %x\n", a >> 2);

	//只有负数在右移的时候，才分逻辑右移(+0替换)和算符右移(+1替换，为了保持负数)，采取那种方式取决于编译器。所以这个代码不具移植性
	int c = -0xff00i16;//z
	printf("c: %x\n", c);
	printf("c<<2: %x\n", c << 2);
	printf("c>>2: %x\n", c >> 2);
	printf("c: %x\n", c);

	system("pause");
	return 0;
}
