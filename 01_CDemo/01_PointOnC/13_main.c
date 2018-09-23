#include <stdlib.h>
#include "13_search_callback.h"
#include "13_switchtable.h"

int main(int argc, char const *argv[])
{
    //1.sample of function point
    Node *root; //fake a root to try
    int desired_value = 0;
    Node *result = NULL;
    result = search_list(root, &desired_value, compare_ints);

    //2.sample of switch table(function point array)
    double result2 = 0, a = 10, b = 3;
    double (*oper_funcs[])(double, double) = {Add, Sub, Mul, Div};
    operation myoper = ADD;
    result2 = caculator(myoper, a, b, oper_funcs);

    return 0;
}

//int (*compare)(void const *, void const *))
int compare_ints(void const *nodeValue, void const *value)
{
    //int *nodeValuetmp = (int *) nodeValue;
    if (*(int *)nodeValue == *(int *)value)
        return 0;
    else
        return 1;
}

double Add(double a, double b)
{
    return a + b;
}
double Sub(double a, double b)
{
    return a - b;
}
double Mul(double a, double b)
{
    return a * b;
}
double Div(double a, double b)
{
    return a / b;
}