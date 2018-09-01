#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdafx.h"

//Page 115, Point on C
//1: return the first character point in source of which matches any characters in chars. Otherwise, return NULL.
char *find_char(char const *source, char const *chars);

//2: delete the substring matched with parameter substr and return 1; otherwist, return 0;
//Just delete the first matched substring if matched multiply.
int del_substr(char *str, char const *substr);

//3. reverse string
void reverse_string(char *string);
void reverse_string01(char *string);
//reverse by recursion
void reverse_string02(char *string);

int main()
{
	// 1.test sample for func find_char()
	// char const *src = "abcde";
	// char const *chs = "xrcbg";
	// printf("begin\n");
	// char *result = find_char(src, chs);
	// if (result != NULL)
	// {
	//     printf("matched character:%c\n", *result);
	// }
	// else
	// {
	//     printf("No match character in source.\n");
	// }

	 //2.test sample for func del_substr()
	char str[10] = "abcdefg";
	char substr[10] = "ab";
	printf("del_substr begin\n");
	int result = del_substr(str, substr);
	if (result != 0)
	{
		printf("str:%s\n", str);
	}
	else
	{
		printf("No matched in str\n");
	}

	// 3.test sample for func reverse_string()
	//char str[10] = "abcef";
	//printf("origin string:%s\n", str);
	//reverse_string02(str);
	//printf("reverse_string:%s\n", str);
	//return 0;
}

char *find_char(char const *source, char const *chars)
{
	if (source == NULL || chars == NULL)
	{
		printf("parameter error;");
		return NULL;
	}

	char const *tmp_chars = chars;
	while (*source++ != '\0')
	{
		tmp_chars = chars;
		while (*tmp_chars++ != '\0')
		{
			if (*source == *tmp_chars)
			{
				return source;
			}
		}
	}

	return NULL;
}

int del_substr(char *str, char const *substr)
{
	if (str == NULL || substr == NULL)
	{
		printf("func del_substr paramter error");
		return 0;
	}
	char *tmp_str = str, *temp = str;
	char *tmp_substr = substr;
	int offset = 0;
	while (*tmp_substr++ != '\0')
		offset++;
	if (offset == 0)
		return 0;

	while (*(temp + offset) != '\0')
	{
		tmp_substr = substr;
		for (; *temp++ == *tmp_substr++;)
		{
			if (*tmp_substr == '\0')
			{
				tmp_str = temp - offset;
				while ((*tmp_str++ = *temp++) != '\0')
					;

				return 1;
			}
		}
	}

	return 0;
}

void reverse_string(char *str) {
	char *last_char;
	for (last_char = str; *last_char != '\0'; last_char++)
		;
	last_char--;

	while (str < last_char)
	{
		char temp;
		temp = *str;
		*str++ = *last_char;
		*last_char-- = temp;
	}
}

void reverse_string01(char *string)
{
	if (string == NULL)
	{
		printf("func del_substr paramter error");
		return;
	}

	char *tmp_str = string;
	int len = 0;
	while (*tmp_str++ != '\0')
		len++;

	printf("len=%d\n", len);

	char tmp_chr;
	for (int i = 0; (len - 2 * i) > 1; i++)
	{
		tmp_chr = *(string + i);
		*(string + i) = *(string + len - i - 1);
		*(string + len - i - 1) = tmp_chr;
	}
	string = tmp_str;
}

//reverse by recursion
void reverse_string02(char *string) {
	if (string == NULL)
	{
		printf("func paramter error");
		return;
	}

	if (*string == '\0')
		return;

	reverse_string02(++string);
	printf("%c", *string);
}