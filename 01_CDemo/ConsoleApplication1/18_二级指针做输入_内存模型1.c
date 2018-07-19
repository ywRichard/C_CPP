#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void printMyArray(char **myArray, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}

void sortMyArray(char **myArray, int num) {
	int i = 0, j = 0;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				tmp = myArray[i];//交换的是内存块
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

//第一种内存模型
void main18()
{
	int i = 0, j = 0;
	int num = 0;

	//指针数组，数组中的每一个元素是指针
	char *myArray[] = { "aaa","bbb","ccc","wwww" };
	//打印
	num = sizeof(myArray) / sizeof(myArray[0]);

	printf("排序之前\n");
	printMyArray(myArray, num);

	sortMyArray(myArray, num);
	//排序

	printf("排序之后\n");
	printMyArray(myArray, num);

	printf("hello....\n");
	system("pause");
	return;
}