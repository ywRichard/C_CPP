#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//求非空格的字符串长度
int getStrCount(char *str, int *pCount) {
	char *p = str;
	int nCount = 0;
	int i, j = 0;

	if (str == NULL || pCount == NULL)
	{
		return -1;
	}
	i = 0;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	*pCount = nCount;

	return 0;
}

int trimSpace(char *str, char *out, int *pCount) {
	char *p = str;
	char *newStr = out;
	int nCount = 0;
	int i, j = 0;

	if (str == NULL || out == NULL || pCount == NULL)
	{
		return -1;
	}
	i = 0;
	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	strncpy(newStr, p + i, nCount);
	newStr[nCount] = '\0';

	*pCount = nCount;

	return 0;
}

//src所指向的内存空间，可以被修改才行
//既做输入又做输出的指针需要特别注意，指针指向的内存空间是否可以被修改。如果是常量就不能被修改
int trimSpace2(char *str, int *pCount) {
	if (str == NULL || pCount == NULL)
	{
		return -1;
	}

	char *p = str;
	int nCount = 0;
	int i = 0, j = 0;

	j = strlen(p) - 1;

	while (isspace(p[i]) && p[i] != '\0')
	{
		i++;
	}

	while (isspace(p[j] && p[j] != '\0'))
	{
		j--;
	}

	nCount = j - i + 1;
	strncpy(str, str + i, nCount);
	str[nCount] = '\0';

	*pCount = nCount;

	return 0;
}

void main141() {
	char *str = "   qwer    ";
	int count = 0;
	char result[20];
	//getStrCount(str, &count);
	//trimSpace(str, result, &count);
	trimSpace2(str, &count);
	printf("str:%s\n", result);
	printf("str len:%d\n", count);

	system("pause");
}