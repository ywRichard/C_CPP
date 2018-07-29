#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

void main241() {
	//数组的定义方式
	int a[] = { 1,2 };
	int b[100] = { 1,3 };
	int c[200] = { 0 };//编译时，就已经确定所有的值为零

	memset(c, 0, sizeof(c));//显示的重置内存块

	//对一维数组 C规定:
	//c 是数组首元素的地址 c+1 步长 4个字节
	//&c 是整个数组的地址  &c+1 步长 200*4

	typedef int(MyArrayType)[5];//定义了一个数据类型，数组数据类型
	MyArrayType myArray;//int myArray[5];

	for (int i = 0; i < 5; i++)
	{
		myArray[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", myArray[i]);
	}

	printf("myArray代表数组首元素的地址 myArray:%d, myArray+1:%d \n", myArray, myArray + 1);
	printf("&myArray代表整个数组的地址 &myArray:%d, &myArray+1:%d \n", &myArray, &myArray + 1);//&myArray+1的步长是4*5=20
}

void main242() {
	char *MyArray1[] = { "111","aaa","bbb" };//指针数组，指针变量的数组
	//定义数组指针变量的方法1
	//用数据类型 *
	{
		//数组指针，指向数组的指针
		typedef int(MyArrayType)[5];//定义了数据类型，数组数据类型

		MyArrayType myArray;//用自定义的数据类型定义变量
		MyArrayType *pArray;//定义一个指针变量，指向一个数组
		{
			//普通指针变量赋值
			int a;
			int *p = NULL;
			p = &a;

			//数组指针
			int myArray2[5];//相当于一级指针
			pArray = &myArray2;//相当于二级指针
			for (int i = 0; i < 5; i++)
			{
				//(*pArray)[i] = i;
				myArray2[i] = i;
			}
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", (*pArray)[i]);
			}
		}


		printf("hello....\n");
		system("pause");
		return;
	}
}

//多维数组做参数，退化过程
void printArray01(int a[3][5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray02(int a[][5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
void printArray03(int(*a)[5]) {
	int i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
}
//验证多维数组线性存储, 二维数组按一维数组打印
void printArray04(int *myArray, int size) {
	if (myArray == NULL)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", myArray[i]);
	}
}

void printKeyWord(char **myArray) {
	if (myArray == NULL)
	{
		return;
	}
	for (int i = 0; myArray[i] != NULL; i++)
	{
		printf("%s\n", myArray[i]);
	}
}

void main243() {
	int a[3][5], i = 0, j = 0;
	int tmp = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	printf("printArray01\n");
	printArray01(a);
	printf("printArray02\n");
	printArray02(a);
	printf("printArray03\n");
	printArray03(a);
	printf("printArray04: 二维数组也是按线性储存的\n");
	printArray04(a, 15);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");

	//a多维数组名，代表?
	printf("a:%d, a+1:%d\n", a, a + 1);//a+1的步长，20个字节，5*4
	printf("&a:%d, &a+1:%d\n", &a, &a + 1);
	{
		//定义一个指向数组的指针变量
		int(*pArray)[5];//告诉编译器，分配4个字节的内存
		pArray = a;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				printf("%d ", pArray[i][j]);
			}
		}
		printf("\n");
	}
	//多维数组名的本质，即数组指针；步长，一维数组的长度
	//(a+i) 代表整个第i行的地址，是二级指针
	//*(a+i) 代表1级指针，第i行首元素的地址
	//*(a+i) + j ===> &a[i][j]
	//*(*(a+i) + j) ===> a[i][j]元素的值

	//==============================================
	//指针数组的自我结束能力, '\0', 0, NULL都是字符串的结束标志
	printf("数组的自我结束\n");
	char *c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};
	char *c_keyword2[] = {
		"while",
		"case",
		"static",
		"do",
		0
	};
	char *c_keyword3[] = {
		"while",
		"case",
		"static",
		"do",
		NULL
	};
	printf("*c_keyword[]\n");
	printKeyWord(c_keyword);
	printf("*c_keyword2[]\n");
	printKeyWord(c_keyword2);
	printf("*c_keyword3[]\n");
	printKeyWord(c_keyword3);


	printf("hello....\n");
	system("pause");
	return;
}