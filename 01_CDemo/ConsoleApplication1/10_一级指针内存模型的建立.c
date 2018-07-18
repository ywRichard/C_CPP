#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main101() {
	char buf[20] = "aaaa";
	char buf2[] = "bbbb";
	char *p1 = "11111";
	char *p2 = malloc(100);
	strcpy(p2, "3333");

	system("pause");
	return;
}