#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

//题目1：输入字符串特征“aaaa,bbbb,cccc,ddd,eee,rrrr”,输出
//a、以逗号分割字符串，形成二维数组，返回结果
//b、返回二维数组行数
int getStrArray01(char *src/*in*/, char myArray[10][20], int *size) {
	if (src == NULL || size == NULL)
	{
		return -1;
	}

	int count = 0;
	char *tmp = NULL;
	char *buf = NULL;
	tmp = src;
	while (strchr(tmp, ',') != NULL)
	{
		buf = tmp;
		tmp = strchr(tmp, ',') + 1;

		strncpy(myArray[count], buf, abs(tmp - buf - 1));
		count++;
	}
	if (tmp != '\0')
	{
		strcpy(myArray[count], tmp);
		count++;
	}

	*size = count;
	return 0;
}
//题目2、通过malloc分配内存的形式输出结果
char **getStrArray02(char *src, int *size) {
	if (src == NULL || size == NULL)
	{
		return NULL;
	}
	int count = 0;
	char *tmp = src;
	char *buf = NULL;
	char *buf1 = NULL;
	while (strchr(tmp, ',') != NULL)
	{
		count++;
		tmp = strchr(tmp, ',') + 1;
	}
	if (tmp != NULL)
	{
		count++;
	}

	tmp = src;
	char **p = (char **)malloc(count * sizeof(char *));
	for (int i = 0; i < count; i++)
	{
		p[i] = (char *)malloc(5 * sizeof(char *));
		memset(p[i], '\0', 5 * sizeof(char *));

		buf = tmp;
		tmp = strchr(tmp, ',') + 1;
		if (i != count - 1)
		{
			strncpy(p[i], buf, abs(tmp - buf - 1));
		}
		else
		{
			strcpy(p[i], buf);
		}
	}

	*size = count;
	return p;
}

//题目3、字符串特征"abcd1111abcd222abcdqqqqqq"
//a.统计"abcd"出现的次数
//b.将字符串替换成"dcba1111dcba222dcbaqqqqqq"

void main23() {
	//test question 1
	char *src = "aaaa,bbbb,cccc,ddd,eee,rrrr";
	int size = 0;
	{
		char result[10][20] = { "\0" };
		getStrArray01(src, result, &size);
		printf("***********question 1**********\n");
		printf("array size if: %d\n", size);
		for (int i = 0; i < size; i++)
		{
			printf("%s\n", result[i]);
		}
	}

	//test question 2
	{
		printf("***********question 1**********\n");
		size = 0;
		char **p2 = getStrArray02(src, &size);
		if (p2 == NULL)
		{
			printf("getStrArray02 error\n");
			return;
		}

		printf("getStrArray02 length is:%d\n", size);
		for (int i = 0; i < size; i++)
		{
			printf("%s\n", p2[i]);
		}

		for (int i = 0; i < size; i++)
		{
			if (p2[i] != NULL)
			{
				free(p2[i]);
			}
		}
		if (p2 != NULL)
		{
			free(p2);
			p2 = NULL;
		}
	}

	//test question 2
	char *src1 = "abcd1111abcd222abcdqqqqqq";

	size = 0;
	{
		printf("***********question 3**********\n");
		char *needle = "abcd";
		int needleLen = strlen(needle);
		int splitStrLen = 0;
		char *str = "dcba";
		char *buf = NULL;
		char *bufTmp = NULL;

		char *myArray[10] = { 0 };
		memset(myArray, '\0', 10);
		buf = src1;
		while (strstr(buf, needle) != NULL) {
			bufTmp = buf;
			buf = strstr(buf, needle);
			if (bufTmp == buf)
			{
				buf = buf + needleLen;
				continue;
			}

			splitStrLen = abs(buf - bufTmp);//count the split string length
			strncpy(myArray[size], bufTmp, splitStrLen);//shift needLen get splitStrlen substr.
			size++;
		}


		printf("%d\n", size);
	}

	printf("hello....\n");
	system("pause");
	return;
}