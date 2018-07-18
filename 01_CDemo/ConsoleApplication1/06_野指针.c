#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main06()
{
	//
	//野指针是指指针变量所指向的内存空间不存在，不可用，或者被释放。
	//产生的原因，指针变量和它所指向的内存空间变量是两个不同的概念
	//释放了指针所指向的内存空间，但是指针变量本身并没有被reset
	//Workaround, 1 & 2

	char *p1 = NULL;//1.定义指针的同时初始化为NULL
	p1 = (char)malloc(100);
	if (p1 = NULL)
	{
		return;
	}
	strcpy(p1, "11112222");

	printf("p1:%s \n", p1);

	if (p1 = !NULL)
	{
		free(p1);//free的是p1指向的内存空间，p1本身没有影响
		p1 = NULL; //2.释放指针所指向的内存空间后，把指针reset为NULL
	}

	if (p1 != NULL)
	{
		free(p1);
	}

	printf("hello....\n");
	system("pause");
	return;
}