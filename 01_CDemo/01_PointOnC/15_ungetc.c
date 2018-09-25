#include <stdio.h>
#include <ctype.h>

int read_int()
{
    int value = 0;
    int ch;

    while ((ch = getchar()) != EOF && isdigit(ch))
    {
        value *= 10;
        value += ch - '0';// convert the literal value from char to number
    }

    ungetc(ch,stdin);
    return value;
}