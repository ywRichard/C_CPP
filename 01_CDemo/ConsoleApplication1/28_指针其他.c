#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//1、在被调用函数中释放内存
int getContentLen01(const char *filename, char **buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (tmp == NULL)
	{
		return -1;
	}
	strcpy(tmp, "aaaaaaaaa");
	*len = 10;
	*buf = tmp;//间接赋值

	return 0;
}

int getContentLen02(const char *filename, char *buf, int *len) {
	char *tmp = NULL;
	tmp = (char *)malloc(100 * sizeof(char));
	if (buf == NULL)
	{
		*len = 10;//第一次调用求内存
	}
	else
	{
		strncpy(tmp, "aaaaaaaaaaaaa", 10);
		*len = 10;
	}
	return 0;
}

int main28() {
	const char *filename = "";
	char *p = NULL;
	int len = 0;

	getContentLen01(filename, &p, &len);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	//第一次调用求长度
	getContentLen02(filename, NULL, &len);
	p = (char *)malloc(len);
	if (p == NULL)
	{
		return;
	}
	//第二次调用求内容
	getContentLen02(filename, p, &len);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	system("pause");
	return;
}