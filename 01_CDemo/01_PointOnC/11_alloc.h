#include <stdlib.h>

#define malloc //don't use call malloc defirectly
#define MALLOC(num,type) (type *)alloc(num)*sizeof(type))
//define a custimzed memory allocator
extern void *alloc(size_t size);