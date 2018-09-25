#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1 = '0';
    int ch2 = '0';
    printf("ch1:%d, ch2:%d", ch1, ch2);
    while ((ch1 = getchar()) != EOF)
    {
        printf(ch1);
    }
    printf("\n");
    system("pause");
}