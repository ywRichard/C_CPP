#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>


//第三种内存模型
void main20()
{
	int i = 0, j = 0;
	char **p2 = NULL;
	int num = 5;
	p2 = (char **)malloc(sizeof(char *) *num);

	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	printf("排序之前\n");
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	char *tmp = NULL;
	char tmpBuf[100];
	//排序 -> 交换指针的指向
	/*for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}*/

	//排序 -> 交换内存的值
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				strcpy(tmpBuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpBuf);
			}
		}
	}

	printf("排序之后\n");
	//排序之后
	for (i = 0; i < num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//释放内存
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	printf("hello....\n");
	system("pause");
	return;
}

//*****************改写******************
char **getMem03(int num) {
	char **p2 = NULL;
	int i = 0;
	p2 = (char **)malloc(sizeof(char *) *num);
	if (p2 == NULL)
	{
		return p2;
	}

	for (i = 0; i < num; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * 100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}

	return p2;
}

void printMyArray03(char **myArray, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", myArray[i]);
		//printf("%s\n", *(myArray+i));
	}
}
void sortMyArray03(char **myArray, int num) {
	if (myArray == NULL)
	{
		printf("sortMyArray error\n");
		return;
	}

	int i = 0, j = 0;
	char *tmp = NULL;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) < 0)
			{
				tmp = myArray[i];//交换的是内存块
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}
void freeMem(char **p2, int num) {
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
}

void main201()
{
	int i = 0, j = 0;
	char **p2 = NULL;
	int num = 5;
	p2 = getMem03(num);

	printf("排序之前\n");
	printMyArray03(p2, num);

	char *tmp = NULL;
	char tmpBuf[100];
	//排序 -> 交换指针的指向
	sortMyArray03(p2, num);

	printf("排序之后\n");
	printMyArray03(p2, num);

	//释放内存
	freeMem(p2, num);
	p2 = NULL;

	printf("hello....\n");
	system("pause");
	return;
}