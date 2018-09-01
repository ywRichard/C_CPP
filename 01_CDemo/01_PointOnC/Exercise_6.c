#include <stdio.h>

//Page 115, Point on C
//1: return the first character point in source of which matches any characters in chars. Otherwise, return NULL.
char *find_char(char const *source, char const *chars);

//2: delete the substring matched with parameter substr and return 1; otherwist, return 0;
//Just delete the first matched substring if matched multiply.
int del_substr(char *str, char const *substr);

//3. reverse string
void reverse_string(char *string);

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

    // 2.test sample for func del_substr()
    // char *str = "abcdefg";
    // char *substr = "cde";
    // printf("del_substr begin\n");
    // int result = del_substr(str, substr);
    // if (result != 0)
    // {
    //     printf("str:%s\n",str);
    // }
    // else
    // {
    //     printf("No matched in str\n");
    // }

    // 3.test sample for func reverse_string()
    char *str = "abcef";
    printf("origin string:%s\n", str);
    reverse_string(str);
    printf("reverse_string:%s\n", str);
    return 0;
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
    char *tmp_str = str;
    char *tmp_substr = substr;
    int offset = 0;
    while (*tmp_substr++ != '\0')
        offset++;
    if (offset == 0)
        return 0;

    while (tmp_str + offset != NULL)
    {
        tmp_substr = substr;
        char *temp = tmp_str;
        for (; *temp++ == *tmp_substr++;)
        {
            if (*tmp_substr == '\0')
            {
                while (*temp++ != '\0')
                    *tmp_str = *temp;
                str = tmp_str;
                return 1;
            }
        }
    }

    return 0;
}

void reverse_string(char *string)
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
        printf("i=%d\n", i);
        tmp_chr = *(string + i);
        printf("*(string+i)=%c, tmp_chr=%c, *(string+len-i)=%c\n", *(string + i), tmp_chr, *(string + len - i - 1));
        *(string + i) = *(string + len - i - 1);
        *(string + len - i - 1) = tmp_chr;
    }

    printf("\n");
}