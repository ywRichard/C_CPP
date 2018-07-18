# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main01()
{
	int a;
	int b;
	a = 10;//直接赋值
	printf("&a: %d\n", &a);//3406084
	//*************通过内存地址间接赋值******************
	//间接赋值 ==> 直接通过内存地址
	//*((int*)3406084) = 200;
	*((int*)&a) = 200;
	printf("a: %d\n", a);

	{
		char * p;
		p = &a;//传递变量的内存地址
		*p = 300;
		printf("p: %d\n", a);
	}

	//*************指针的步距******************
	int c[10];
	//c,&c相同，c代表数组首元素的指针
	//c+1，&c+1不同，&c代表整个数组的地址
	printf("c:%d,c+1:%d,&c:%d,&c+1:%d\n", c, c + 1, &c, &c + 1);


	printf("hello...\n");
	system("pause");
	return;
}