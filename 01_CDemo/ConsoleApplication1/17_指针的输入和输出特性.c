#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//指针做输出 -> 被调用函数分配内存
//指针做输入 -> 主调用函数分配内存
//求文件中的两段话的长度
int getMem17(char **myp1, int *mylen1, char **myp2, int *mylen2) {
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	tmp1 = (char *)malloc(100);
	if (tmp1 == NULL)
	{
		return -1;
	}
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);

	*myp1 = tmp1;//间接修改实参p1的值

	tmp2 = (char *)malloc(100);
	if (tmp2 == NULL)
	{
		return -1;
	}
	strcpy(tmp2, "12343423");
	*mylen2 = strlen(tmp2);

	*myp2 = tmp2;//间接修改实参p1的值

	return 0;
}

//将实参赋值给二级指针，可以保存实参一级指针的地址，在释放的实参指向的内存空间后还可以释放实参
int getMem_Free(char **myp) {
	if (myp == NULL)
	{
		return -1;
	}
	free(*myp);//释放指针变量的内存空间
	*myp = NULL;//把实参修改成NULL

	return 0;
}
//一级指针释放实参，通过一级指针，只能讲内存空间的地址通过实参传递给形参，但是形参和实参没有任何联系。
int getMem_Free0(char *myp) {
	if (myp==NULL)
	{
		return -1;
	}
	free(myp);//释放指针指向的内存空间
	//myp == NULL;//释放的是在栈上分配的形参指针，但是实参指针不会被释放。

	return 0;
}

void main17()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMem17(&p1, &len1, &p2, &len2);
	printf("p1: %s\n", p1);
	printf("p2: %s\n", p2);

	/*getMem_Free(&p1);
	getMem_Free(&p2);*/

	getMem_Free0(p1);
	getMem_Free0(p2);

	printf("hello....\n");
	system("pause");
	return;
}