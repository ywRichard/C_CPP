#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//指向常整型变量的指针
void getMem1601(const char *p) {
	p = 1;
	p = 3;
	//*p = "asd";
	//p[1] = 'a';
	return;
}

//常指针
void getMem1602(char *const p) {
	//p = 1;
	//p = 3;
	*p = 3;
	p[1] = 'a';
	return;
}

//指向常整形的常指针
void getMem1603(const char * const p) {
	/*p = 1;
	p = 3;
	*p = 3;
	p[1] = 'a';*/
	return;
}

void main16()
{
	//两者相同，代表一个常整形
	const int a = 1;
	int const b = 1;

	//指向常整形的指针，指针变量可以被修改，但是指向的内存空间不能被修改
	const char *c = "c";

	//常指针，指针变量不可以被修改，但是指向的内存空间可以被修改
	char * const d = "d";

	//指向常整型的常指针，指针变量和指向的内存空间都不能被修改
	const char * const e = "e";

	//结论c语言中，可以通过指针间接地修改const修饰的变量，const修饰的变量是个伪命题
	const int p = 10;
	//p = 11;
	{
		int *p = &a;
		*p = 100;
		printf("a:%d \n", a);
	}

	printf("hello....\n");
	system("pause");
	return;
}