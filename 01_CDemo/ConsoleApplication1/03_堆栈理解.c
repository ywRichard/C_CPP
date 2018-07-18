# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//堆
char *getMem(int num) {
	char *p1 = NULL;//临时变量分配在栈上，由编译器自动分配释放；
	p1 = (char*)malloc(sizeof(char) *num);//malloc的内存分配在堆上，堆区一般由程序员分配释放，或程序结束时由操作系统释放
	if (p1 == NULL) {
		return NULL;
	}
	//在函数结束时，指针变量p1占用的内存会被编译器释放，但是p1所指向的内存空间由于是malloc出来的，分配在堆上，函数结束时并不会被回收。
	return p1;
}

//栈
//理解指针的关键是内存，没有内存就没有指针
char *getMem2() {
	char buf[64];
	strcpy(buf, "123456789");
	printf("buf:%s\n", buf);
	return buf;//return的不是整个内存块（64个字节），而是把内存块的首地址（0xaa11）
}

void main03()
{
	char *tmp = NULL;
	tmp = getMem(10);//返回malloc出来内存空间的首地址。
	if (tmp == NULL)
	{
		return;
	}
	//strcpy(tmp, "111222333444111222333444111222333444111222333444");//内存应该会溢出，出现“ntdll.pdb not loaded”
	strcpy(tmp, "11444");

	tmp = getMem2();
	printf("hello... tmp:%s.\n", tmp);

	//内存地址其实是一串数字，可以存在指针中，也可以存在int类型中。
	//但是指针不但可以保存内存地址，同时可以定义指向的内存储存的变量的数据类型。
	int * pint = NULL;
	pint = (int *)malloc(sizeof(int));
	int a = (int *)malloc(sizeof(long));
	printf("pint:%d\n", pint);
	printf("a:%d\n", a);

	//打印一下不同类型变量的长度
	printf("###################\n");
	printf("int length:%d\n", sizeof(int));
	printf("char length:%d\n", sizeof(char));
	printf("long length:%d\n", sizeof(long));
	printf("short length:%d\n", sizeof(short));
	printf("double length:%d\n", sizeof(double));
	printf("char[8] length:%d\n", sizeof(char[8]));
	printf("int[8] length:%d\n", sizeof(int[8]));

	system("pause");
	return;
}