#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

typedef struct Student {
	int age;
	char name[64];
	char *alise;//申明指针变量之后，一定要为指针分配指向的内存。
	char **subname;
	int id;
} Student;

int createStudentArr(Student **p, int num, int subNum) {
	Student *tmp = (Student *)malloc(sizeof(Student)*num);
	if (tmp == NULL)
	{
		return -1;
	}

	for (int i = 0; i < num; i++)
	{
		tmp[i].alise = (char *)malloc(60);

		char **sp = (char *)malloc(sizeof(char*)*subNum);
		for (int j = 0; j < subNum; j++)
		{
			sp[j] = (char *)malloc(60);
		}
		tmp[i].subname = sp;
	}
	*p = tmp;
	return 0;
}

int printfStudentArr(Student *s, int num) {
	if (s == NULL)
	{
		return;
	}
	for (int i = 0; i < num; i++)
	{
		printf("name:%s ", s[i].name);
		printf("age:%d ", s[i].age);
		printf("alise:%s\n", (s[i].alise));
	}
}
int freeStudentArr(Student **s, int num, int subNum) {
	if (s != NULL)
	{
		for (int i = 0; i < num; i++)
		{
			if ((*s)[i].alise != NULL)
			{
				free((*s)[i].alise);
			}

			char **p = (*s)[i].subname;
			if (p != NULL)
			{
				for (int j = 0; j < subNum; j++)
				{
					if (p[j] != NULL)
					{
						free(p[j]);
						p[j] = NULL;
					}
				}
				free(p);
				(*s)[i].subname = NULL;
			}
		}
		free(*s);
		s = NULL;
	}

	return 0;
}

void main253() {
	int ret = 0;
	int num = 3;
	int subNum = 3;
	Student *pStu = NULL;
	ret = createStudentArr(&pStu, num, subNum);

	for (int i = 0; i < num; i++)
	{
		printf("\n enter the student age:");
		scanf("%d", &(pStu[i].age));
		printf("\n enter the student alise:");
		scanf("%s", pStu[i].alise);

		for (int j = 0; j < subNum; j++)
		{
			printf("enter the student subname%d:", j);
			scanf("%s", pStu[i].subname[j]);
		}

	}
	printfStudentArr(pStu, num);
	freeStudentArr(&pStu, num, subNum);

	system("pause");
	return;
}