#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//
int inverse01(char *str1) {
	if (str1 == NULL)
	{
		printf("parameter is error\n");
		return -1;
	}

	int length = strlen(str1);

	char *p1 = str1;
	char *p2 = str1 + length - 1;

	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;

		p1++;
		p2--;
	}
}

//递归学习的顺序
//1.递归的方式，逆向打印
//2.全局变量保存结果
//3.局部变量保存结果，指针做函数参数

//1.递归的方式，逆向打印
void inverse02(char *p) {
	if (p == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*p == '\0')//递归结束的条件
	{
		return;
	}

	inverse02(p + 1);//此时没有执行打印，而是执行了函数调用。让字符串的每个地址入栈
	printf("%c", *p);
}

char g_buf[1000];

//2.递归和全局变量（把逆序的结果存入变量）
void inverse03(char *p) {
	if (p == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*p == '\0')//递归结束的条件
	{
		return;
	}

	inverse03(p + 1);//此时没有执行打印，而是执行了函数调用。让字符串的每个地址入栈
	strncat(g_buf, p, 1);
}

//3.递归和局部变量，指针做函数参数
void inverse04(char *p, char *bufResult) {
	if (p == NULL || bufResult == NULL)//递归结束的异常条件
	{
		return;
	}
	if (*p == '\0')//递归结束的条件
	{
		return;
	}

	inverse04(p + 1, bufResult);//此时没有执行打印，而是执行了函数调用。让字符串的每个地址入栈
	strncat(bufResult, p, 1);
}

void main151() {
	char buf[] = "abcdefg";

	//inverse01(buf);
	//printf("buf:%s\n", buf);

	//递归逆向打印
	//inverse02(buf);

	//递归 -> 全局变量
	//memset(g_buf, 0, sizeof(g_buf));
	//inverse03(buf);
	//printf("g_buf:%s\n", g_buf);

	//递归 -> 局部变量
	char myBuf[1024] = { 0 };
	inverse04(buf, myBuf);
	printf("myBuf:%s\n", myBuf);

	system("pause");
}