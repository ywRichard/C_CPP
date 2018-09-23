#include <stdio.h>
#define TRUE 1

void process_standard_input(void);
void process_file(char *file_name);

int option_a, option_b;

void main(int argc, char const *argv[])
{
    char opt = NULL;
    while (*++argv != NULL && **argv == '-') //traverse parematers
    {
        while (opt = *++*argv != '\0')//search subparameters of every parameter
        {
            switch (opt)
            {
            case 'a':
                option_a = TRUE;
                break;
            case 'b':
                option_b = TRUE;
                break;
            }
        }
    }

    if (*argv == NULL)
    {
        process_standard_input();
    }
    else
    {
        do
        {
            process_file(*argv);
        } while (*++argv != NULL);
    }

    return 0;
}
