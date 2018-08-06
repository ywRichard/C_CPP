#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

//==================Exam 1====================
//1.构造结构体变量
//2.用name排序
typedef struct Student {
	int ID;
	int age;
	char *name;
}Student;

int createStudent(Student **p, int num) {
	Student *tmp = (Student *)malloc(sizeof(Student)*num);
	if (tmp == NULL)
		return -1;
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < num; i++)
	{
		tmp[i].name = (char *)malloc(sizeof(char*) * 10);
		memset(tmp[i].name, 0, sizeof(tmp[i].name));
	}

	*p = tmp;
	return 0;
}

int sortStudent(Student *p, int num) {
	if (p == NULL)
	{
		return -1;
	}
	Student tmp;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (strcmp(p[i].name, p[j].name) < 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	return 0;
}

int freeStudent(Student **p, int num) {
	if (p == NULL)
	{
		return -1;
	}

	for (int i = 0; i < num; i++)
	{
		char *tmp = (*p)[i].name;
		if (tmp != NULL)
		{
			free(tmp);
			(*p)[i].name = NULL;
		}
	}
	free(*p);
	p == NULL;
}

int printStudent(Student *p, int num) {
	if (p == NULL)
	{
		return -1;
	}

	for (int i = 0; i < num; i++)
	{
		printf("Student %d name is: %s\n", i, p[i].name);
	}
	return 0;
}

void main261() {
	int ret = 0;
	int i = 0, j = 0;
	int num = 3;

	Student *myStu = NULL;
	ret = createStudent(&myStu, num);
	if (ret != 0)
	{
		printf("createStudent err\n");
		return;
	}

	for (i = 0; i < num; i++)
	{
		printf("enter student %d ID:", i);
		scanf("%d", &(myStu[i].ID));
		printf("enter student %d age:", i);
		scanf("%d", &(myStu[i].age));
		printf("enter student %d Name:", i);
		scanf("%s", myStu[i].name);
	}

	printStudent(myStu, num);
	ret = sortStudent(myStu, num);
	if (ret != 0)
	{
		printf("sortStudent err\n");
		return;
	}
	printf("after sort\n");
	printStudent(myStu, num);
	freeStudent(&myStu, num);

	system("pause");
	return;
}

//==================Exam 2====================
//把第一种内存模型和第二种内存模型copy到第三种内存模型中，排序并打印
int sort(char **myp1/*in*/, int num1, char(*myp2)[30], int num2, char ***myp3, int *num3) {
	if (myp1 == NULL || myp2 == NULL)
	{
		return -1;
	}
	int i = 0, j = 0;
	char **p3 = NULL;
	p3 = (char **)malloc((num1 + num2) * sizeof(char *));
	if (p3 == NULL)
	{
		return -1;
	}

	int tmpLen = 0;
	for (i = 0; i < num1; i++)
	{
		tmpLen = strlen(myp1[i]) + 1;//+1, 把字符串的结尾'\0'也加上
		p3[i] = (char *)malloc(tmpLen * sizeof(char));
		if (p3[i] == NULL)
		{
			return -1;
		}
		strcpy(p3[i], myp1[i]);
	}

	for (j = 0; j < num2; j++, i++)
	{
		tmpLen = strlen(myp2[j]);
		p3[i] = (char *)malloc(tmpLen * sizeof(char));
		if (p3[i] == NULL)
		{
			return -1;
		}
		strcpy(p3[i], myp2[j]);
	}

	char *tmp = NULL;
	tmpLen = num1 + num2;
	//排序
	for (i = 0; i < tmpLen; i++)
	{
		for (j = i + 1; j < tmpLen; j++)
		{
			if (strcmp(p3[i], p3[j]) > 0)
			{
				tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}

	*myp3 = p3;
	*num3 = tmpLen;
	return 0;
}

void sortFree01(char **p, int len) {
	int i = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
}

void sortFree02(char ***myp, int len) {
	if (myp == NULL)
	{
		return;
	}
	char **p = NULL;
	p = *myp;//还原成二级指针
	for (int i = 0; i < len; i++)
	{
		free(p[i]);
	}
	free(p);
	//myp 是实参地址
	*myp = NULL;//间接赋值是指针存在的最大价值

}

int main262() {
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbb" };
	char buf2[10][30] = { "1111","333333","222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);//*p1即数组首元素地址，指针数组的大小/首元素的大小
	len2 = 3;
	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("func sort() err:%d \n", ret);
		return ret;
	}

	for (i = 0; i < len3; i++)
	{
		printf("%s\n", p3[i]);
	}

	printf("hello...\n");
	system("pause");
	return ret;
}