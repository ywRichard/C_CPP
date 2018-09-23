

#ifndef operation
    typedef enum
    {
        ADD,
        SUB,
        MUL,
        DIV
    } operation;
#endif

double (*oper_func[])(double, double);
double caculator(operation opre, double a, double b, double (*oper_func[])(double, double));