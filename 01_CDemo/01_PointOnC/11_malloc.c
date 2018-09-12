#include "alloc.h"

//use the custimzed memory allocator what rare to cause error
void function()
{
    int *new_memory;
    new_memory = MALLOC(25, int);
}