#include <stdlib.h>
#include "13_switchtable.h"

double caculator(operation opre, double a, double b, double (*oper_func[])(double, double))
{
    double result = 0;
    switch (opre)
    {
    case ADD:
        result = oper_func[0](a, b);
        break;
    case SUB:
        result = oper_func[1](a, b);
        break;
    case MUL:
        result = oper_func[2](a, b);
        break;
    case DIV:
        result = oper_func[3](a, b);
        break;
    }

    return result;
}
