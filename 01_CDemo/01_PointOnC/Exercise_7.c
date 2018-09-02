#include<stdarg.h>

//Example of book for optional parameter function
float average(int n_values,...) {
	va_list var_arg;
	int count;
	float sum = 0;
	va_start(var_arg, n_values);
	for (count = 0; count < n_values; count++)
	{
		sum += va_arg(var_arg, int);
	}

	va_end(var_arg);
	return sum / n_values;
}