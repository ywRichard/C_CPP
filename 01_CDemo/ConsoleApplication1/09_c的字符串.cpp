#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//一级指针的典型用法
//数组和字符串

//C语言风格的字符串
//1.以0结尾的字符串,0是int类型的
//2.没有字符串类型，通过字符数组来模拟
//3.字符串的内存分配，堆 栈 全局区
void main91() {
	//1、指定长度
	char buf2[100] = { 'a','b','c','d' };//未指定的[4]-[99]，由零代替（不同的编译器是否会不一样？）
	//char buf3[2]= { 'a','b','c','d' };//编译不通过

	//2、不指定长度
	char buf1[] = { 'a','b','c','d' };//编辑器会计算元素个数


	printf("buf2:%s \n", buf2);
	printf("buf2[88]:%s \n", buf2[88]);

	system("pause");
	return;
}

//用字符串来初始化字符数组
//strlen() 字符串的长度，不包括0
//sizeof() 内存块的大小
void main92() {
	char buf3[] = "abcd";//buf3 作为字符数组 5个字节；作为字符串，4个字节

	//字符串
	int len = strlen(buf3);
	printf("buf3字符串的长度:%d \n", len);//4，字符串的长度，不包括0

	//数组，数组是一种数据类型，数据类型的本质是固定大小内存块的别名
	int size = sizeof(buf3);
	printf("buf3数组所占内存空间大小:%d \n", size);//5，内存块的大小

	{
		char buf4[128] = "wert";
		printf("buf[100]:%d \n", buf4[100]);
	}

	printf("hello....\n");
	system("pause");
	return;
}

//通过数组下标和指针操作数组，剖析[]和*p的本质
void main93() {
	char *p = NULL;
	char buf5[128] = "abcdefg";//buf

	printf("strlen(buf5):%d\n", strlen(buf5));//7,不管数组多大，strlen只取到第一个0位置
	printf("sizeof(buf5):%d\n", sizeof(buf5));//128

	//字符串结尾的0或者填补空位的0都是int类型的，遇到第一个0字符串就结束
	{
		char buf6[100] = "qwe0120qwe";
		printf("strlen(buf6):%d\n", strlen(buf6));
	}

	//[]和*p本质上是一样的，[]是为了符合人的阅读习惯；
	//buf5[i]===>buf5[0+i]===>*(buf5+i)，编译器会数组做类似的转换

	for (int i = 0; i < strlen(buf5); i++)
	{
		printf("%c", buf5[i]);
	}
	printf("\n");

	p = buf5;//buf5，代表数组首元素的地址
	for (int i = 0; i < sizeof(buf5); i++)
	{
		if (i < strlen(buf5))
			printf("%c", *(p + i));
		else
			printf("%d", *(p + i));//把零输出
	}
	printf("\n");

	//直接用buf5操作
	for (int i = 0; i < strlen(buf5); i++)
	{
		printf("%c", *(buf5 + i));
	}
	printf("\n");

	printf("hello....\n");
	system("pause");
	return;
}

//为什么不能直接操作数组变量，而可以间接通过指针变量
//普通指针变量和内存首地址的区别
//buf5是一个指针，只读的常量 buf5是一个常量指针，析构内存的时候保证buf5所指向的内存空间安全释放。
//如果buf5能够被随意的赋值，指向其他的内存空间。OS就能够析构之前所指向的内存空间。
//{
//	//buf5 = buf5 + 1;
//	//buf5 = 0x11;
//}