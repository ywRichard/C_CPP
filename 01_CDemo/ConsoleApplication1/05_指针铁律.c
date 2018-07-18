#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char *getStr() {
	char *tmp = NULL;
	tmp = "abcedfg";//常量区，函数结束后内存空间不会被释放
	return tmp;
}

void main05()
{
	int a = 10;
	char *p1 = 100;
	char ****p2 = 1000;
	long *p3 = NULL;
	char *p4 = (char *)malloc(1);
	//不管是在堆上还是在栈上，不管是malloc还是编译器在栈上自动分配，不管数据类型。指针变量的都被分配4个字节的内存。
	//是不是可以认为，不管什么类型的指针变量，指针本身都是int类型的。
	//储存的是指向内存的首地址的值，为指针变量定义的数据类型是表明所执向的内存中储存值的数据类型
	printf("a:%d, p1:%d, p2:%d, p3:%d, p4:%d\n", sizeof(a), sizeof(p1), sizeof(p2), sizeof(p3), sizeof(p4));
	printf("char:%d\n", sizeof(char));

	//*就像把钥匙，可以通过一个地址(&A)去修改变量a标示的内存空间。
	//变量a不存在所标示的内存空间，变量也占内存但是存在于代码区。a相当于所标示内存空间地址的别名，内存空间储存是值
	//*p=，写内存
	//=*p，读内存
	{
		int *p3 = NULL;
		p3 = &a;
		*p3 = 20;//*p3 == a, 间接修改a的值

		int c = 0;
		c = *p3;//c=20
		printf("c:%d\n", c);
	}

	{
		//不断给指针赋值，就相当于不停的改变指针的指向
		char *p5 = NULL;
		p5 = (char*)malloc(100);
		p5 = (char*)malloc(200);
	}

	{
		char *p = getStr();
		printf("p:%s\n", p);
		//修改内存是要确保指向的内存能够被修改
		*(p + 2) = 'r';//尝试修改常量区的内存，报错
		printf("p:%s\n", p);
	}
	printf("hello... \n");
	system("pause");
	return;
}