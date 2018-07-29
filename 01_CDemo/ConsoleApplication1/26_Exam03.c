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
