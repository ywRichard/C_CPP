# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char* getChar1() {
	char *p1 = "abcdefg1";
	return p1;
}

char* getChar2() {
	char *p2 = "abcdefg1";
	return p2;
}

void main02()
{
	char* p1 = NULL;
	char* p2 = NULL;
	printf("&p1:%d;&p2:%d\n", &p1, &p2);
	p1 = getChar1();
	p2 = getChar2();
	//常量会储存在内存四区的常量区中，如果两个指针变量指向的常量相同，那么这两个指针变量的值（指向的内存地址）相同
	printf("p1:%s;p2:%s\n", p1,p2);//输出指针指向的变量内容
	printf("p1:%d;p2:%d\n", p1,p2);//输出指针地址
	printf("&p1:%d;&p2:%d\n", &p1, &p2);
	//在C语言中字符串是char[]，内存字节数 = 字节数+1(有结束符)；
	//如果输char类型，直接分配4个字节的内存和int一样
	printf("sizeof(str1):%d;sizeof(str2):%d\n", sizeof("abcdefg1"), sizeof('a'));

	int* p3 = NULL;
	printf("p3:%d\n", p3);

	p3 = 10;
	printf("p3:%d\n", p3);
	printf("p3:%d\n", &p3);

	int p4 = 20;
	printf("p4:%d\n", &p4);

	printf("hello...\n");
	system("pause");
	return;
}