#include <stdio.h>
#include <stdlib.h>

//list command line parameter
int main(int argc, char const *argv[])
{
    while (*++argv != NULL)//skip first parameter
    {
        printf("%s\n", *argv);
    }
    return EXIT_SUCCESS;
}
