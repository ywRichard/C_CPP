#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//encapsulation, print
//问题的本质：内存模型2的myArray+1 和 内存模型1的myArray+1 不一样。
//指针的步长不一样，因为指针所指向的内存空间的数据类型不一样。
//void printMyArray1_err(char **myArray, int num) {
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%s\n", myArray[i]);
//		//printf("%s\n", *(myArray+i));
//	}
//}

void printMyArray02(char myArray[10][30], int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}

void sortMyArray02(char myArray[10][30], int num) {
	int i = 0, j = 0;
	char tmpBuf[30];

	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				strcpy(tmpBuf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}
}

//第二种内存模型
void main19()
{
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];

	char myArray[10][30] = { "aaa","bbbb","ccccc","ddddddd" };
	//myArray, 编译器只会关心数据类型内存的分配，即数组共有几行几列，这里是10行30列；
	//myArray+1，多维数组中 +1 代表的是指向下一行的内存，即跳过30列；而不是指向下一列。这就是多维数组的本质
	{
		int len1 = sizeof(myArray);
		int len2 = sizeof(myArray[0]);
		int size = len1 / len2;
		printf("len1:%d, len2:%d size:%d\n", len1, len2, size);
	}

	printf("sort before\n");
	//print
	printMyArray02(myArray, num);

	sortMyArray02(myArray, num);

	printf("sort after\n");
	printMyArray02(myArray, num);

	printf("hello....\n");
	system("pause");
	return;
}