#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
//练习1、去掉字符串的两端的空格
int TrimSpace(char *source/*in*/, char *dest) {
	if (source == NULL || dest == NULL)
	{
		printf("para is null \n");
		return -1;
	}

	char *tmpSrc = source;
	char *tmpDest = dest;

	while (*tmpSrc != '\0') {
		if (*tmpSrc != ' ')
		{
			*tmpDest++ = *tmpSrc++;
		}
		else
		{
			*(tmpDest) = '\0';
			tmpSrc++;
		}
	}

	return 0;
}

//练习2、挑选出字符串中的奇数和偶数组成两个新的字符串，并通过参数传递给主函数打印.
int isNum(char c) {
	int n = c;
	return (n >= 48) && (n <= 57);
}
int getStr1Str2(char *source, char *buf1/*even*/, char *buf2/*odd*/) {
	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		printf("parameter is err.\n");
		return -1;
	}

	char *tmpSrc = source;
	char *tmpBuf1 = buf1;
	char *tmpBuf2 = buf2;

	while (*tmpSrc != '\0')
	{
		if (isNum(*tmpSrc))
		{
			if (*tmpSrc % 2 == 0)
			{
				*tmpBuf1++ = *tmpSrc++;
				*tmpBuf1 = '\0';
			}
			else
			{
				*tmpBuf2++ = *tmpSrc++;
				*tmpBuf2 = '\0';
			}
		}
		else
		{
			*tmpSrc++;
		}
	}

	return 0;
}

//练习3、模拟键值对集合
//从字符串中提取键和值
void getKVimp1(char *src, char *key, char *value)
{
	char *tmpSrc = src;
	while (*tmpSrc != '=')
	{
		*key++ = *tmpSrc++;//get key
	}
	*key = '\0';
	tmpSrc++;

	while (*value++ = *tmpSrc++);//get value
}
void getKVimp2(char *src, char *key, char *value)
{
	char *bufSrc = src;
	int len = (strstr(bufSrc, "=") - bufSrc);
	for (int i = 0; i < len; i++)
	{
		*key++ = *bufSrc++;
	}
	*key = '\0';
	bufSrc++;
	while (*value++ = *bufSrc++);
}

int getKeyValue(char *src, char *keyBuf, char *valueBuf, int *valueLen) {
	if (src == NULL || keyBuf == NULL || valueBuf == NULL || valueLen == NULL)
	{
		printf("getKeyValue parameter err\n");
		return -1;
	}

	char srcBuf[100];
	char *tmpkeyBuf = keyBuf;
	char *tmpValueBuf = valueBuf;

	if (TrimSpace(src, srcBuf) != 0)
	{
		printf("TrimSpace Error\n");
		return -1;
	}
	printf("tmpSrc:%s\n", srcBuf);

	//getKVimp1(srcBuf, tmpkeyBuf, tmpValueBuf);
	getKVimp2(srcBuf, tmpkeyBuf, tmpValueBuf);

	*valueLen = strlen(tmpValueBuf);

	return 0;
}

int getKeyValue01(char *src, char *keyBuf, char *valueBuf, int *valueLen) {
	if (src == NULL || keyBuf == NULL || valueBuf == NULL || valueLen == NULL)
	{
		printf("getKeyValue parameter err\n");
		return -1;
	}

	char buf[1024] = {0};
	char *bufP = buf;
	do {
		if (!isspace(*src))
		{
			*bufP++ = *src;//如何用指针操作数组
		}
	} while (*src++ != '\0');

	char *addr = strstr(buf, "=");

	if (addr == NULL)
	{
		printf("miss =");
		return -1;
	}

	int len = 0;
	if (addr >= buf)
		len = (addr - buf);
	else
		len = buf - addr;

	strncpy(keyBuf, buf, len);//不会添加'\0'
	*valueLen = strlen(buf) - len - 1;
	strncpy(valueBuf, addr + 1, *valueLen);//不会添加'\0'
}

void main131() {
	int ret = 0;
	//练习1
	{
		char *buf = "   ewererrdfgdfgdfg  ";
		char dest[5];
		//ret = TrimSpace(NULL, dest);
		ret = TrimSpace(buf, dest);
		if (ret != 0)
		{
			printf("TrimSpace is Error \n");
			return;
		}
	}

	//练习2
	{
		char *mySrc = "1a2b3d4z";
		char buf1[5];
		char buf2[5];
		ret = getStr1Str2(mySrc, buf1, buf2);
		if (ret != 0)
		{
			printf("getStr1Str2 is Error \n");
			return;
		}
		printf("buf1:%s; buf2:%s \n", buf1, buf2);
	}

	//练习3
	printf("++++++++++练习3++++++++++\n");
	{
		char *buf = "  abcd   =   12345678    ";
		char key[10];
		char value[10];
		int len = 0;
		/*getKeyValue(buf, key, value, &len);
		printf("getKeyValue -> key:%s; value:%s; len:%d\n", key, value, len);*/
		getKeyValue01(buf, key, value, &len);
		printf("getKeyValue01 -> key:%s; value:%s; len:%d\n", key, value, len);
	}

	system("pause");
	return;
}

