#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//1、封装接口和函数
//2、从主函数中抽离
int getCount(char *source /*in*/, char *subStr /*in*/, int *count ) {
	if (source == NULL || subStr == NULL || count == NULL)
	{
		printf("getCount Parameter error\n");
		return -1;
	}

	//不要轻易改变形参的值
	char *tmpSource = source;
	char *tmpSubStr = subStr;
	int myCount = 0;
	while (tmpSource = strstr(tmpSource, tmpSubStr))
	{
		myCount++;
		tmpSource = tmpSource + strlen(tmpSubStr);
		if (*tmpSource == '\0')
			break;
	}
	*count = myCount;//间接赋值是指针最大的意义
	return 0;
}
void main120()
{
	int ncount = 0;
	char *p = "11abcd2342abcd4434343abcdertkjgf343abcdwrwerwv";
	//do while模型
	{
		/*do
		{
			p = strstr(p, "abcd");
			if (p != NULL)
			{
				ncount++;
				p = p + strlen("abcd");
			}
			else
				break;
		} while (*p != '\0');*/
	}
	//while模型
	{
		/*while (p = strstr(p, "abcd"))
		{
			ncount++;
			p = p + strlen("abcd");
			if (*p == '\0')
				break;
		}*/
	}

	//封装的API函数
	{
		int ret = getCount(p, "abcd", &ncount);
		if (ret != 0)
		{
			printf("getCount err:%d\n", ret);
			return;
		}
		printf("ncount:%d\n", ncount);
	}


	//'\0'和NULL，都为空
	{
		char str1 = '\0';
		char *str2 = NULL;

		if (str1 == str2)
		{
			printf("true\n");
			printf("str1: %x\n", &str1);
		}
		else
			printf("false\n");

	}
	system("pause");
	return;
}