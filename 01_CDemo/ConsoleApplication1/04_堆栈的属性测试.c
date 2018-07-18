#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void TestStackOrientation()
{
	//假定：a>b，开口向下；a<b，开口向上
	//栈的开口方向，在release和debug下开口方向不同。根据操作系统的不同，栈开口的方向也不一样。
	//通常栈的开口向下，为了栈的溢出。因为在建立栈的时候，第一个元素的地址为最大值， 随着压入的元素增加栈的地址依次减小，防止了栈的溢出。
	int a;
	int b;

	//不管栈的开口方向是向上还是向下，buf的内存地址buf+1都是向上的
	char buf[128];
	printf("&a: %d, &b: %d\n", &a, &b);
}

void main04()
{
	TestStackOrientation();
	printf("hello... \n");
	system("pause");
	return;
}