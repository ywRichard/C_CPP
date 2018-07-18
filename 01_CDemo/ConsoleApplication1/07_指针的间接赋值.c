#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//*****************************1级指针区域**********************************

//将实参的内存地址传递给形参，即在栈上重新分配的指针变量，指针可以根据内存地址指向内存空间进行间接地修改。
int getFileLen(int *p) {
	*p = 50;
}

//普通形参专递的是变量的值，在栈上重新分配变量之后就与实参没有联系了。
//形参的属性，可以通过形参传递实参的方式来初始化变量
int getFileLen3(int b) {
	b = 100;
	return b;
}

//1级指针，用来间接修改变量的值
void main71() {
	int a = 10;
	int *p = NULL;

	a = 20;//直接修改a的值
	p = &a;
	*p = 30;//间接修改 -> p的值是a的地址，*p指向的内存空间就是a的内存空间
	printf("a:%d\n", a);

	getFileLen(*p);//通过指针实参，间接地修改指针所指向的内存空间的变量值
	printf("a:%d\n", a);
	getFileLen3(a);//如果是非指针
	printf("a:%d\n", a);

	printf("hello....\n");
	system("pause");
	return;
}

//*****************************2级指针区域**********************************

//在变量前无论有多少个*, 都是普通的指针变量；有几个*就是几级指针变量，其实就是指向依次指向保存上一级变量值的内存地址
void getMem3(char **p2) {
	*p2 = 400;//p2的值是pa的地址
}

//如果形参数1级指针，p2的值是固然是p1的地址，
void getMem4(char *p2) {
	//printf("&p2:%d\n", p2);
	//printf("*p2:%d\n", *p2);
	//*p2 = 800;//但是由于缺少*，无法指向p1的内存空间，所以p2所做的任何更改都与p1无关
	//printf("&p2:%d\n", p2);
	//printf("*p2:%d\n", *p2);

	*p2 = 800;//但是由于缺少*，无法指向p1的内存空间，所以p2所做的任何更改都与p1无关
}

//2级指针，用来间接修改1级指针变量的值
void main72() {
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 0x11;
	p2 = 0x22;

	p1 = 0x111;//直接修改p1的值
	printf("p1:%d\n", p1);

	p2 = &p1;//p2是p1的地址
	*p2 = 100;//间接修改p1的值
	printf("p1:%d\n", p1);

	{
		*p2 = 200;//间接修改p1的值
		printf("p1:%d\n", p1);
	}

	getMem3(&p1);
	printf("p1:%d\n", p1);

	getMem4(&p1);
	printf("p1:%d\n", p1);
}

//*****************************间接赋值的意义**********************************
//主函数和被调用函数通过内存交换运算结果
int getMem5(char **myP1, int *myLen1, char **myP2, int *myLen2) {
	int ret = 0;
	char *tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "113223");

	//间接赋值
	*myLen1 = strlen(tmp1);//1级指针
	*myP1 = tmp1;//2级指针

	tmp2 = (char *)malloc(200);
	strcpy(tmp2, "aaadddccc");
	*myLen2 = strlen(tmp2);
	*myP2 = tmp2;

	return ret;
}

void main73() {
	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMem5(&p1, &len1, &p2, &len2);
	if (ret != 0) {
		printf("func getMem5() err:%d\n", ret);
		return ret;
	}

	printf("p1:%d\n", p1);
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}

	printf("p2:%d\n", p2);
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
}

//*****************************间接赋值的意义**********************************
//主函数和被调用函数通过内存交换运算结果
void main74() {
	//条件1：定义两个变量（函数之间，形参和实参）
	//条件2：关联，即取变量地址并赋值给指针（把实参地址赋给形参）
	//条件3：*p，形参间接修改实参的值

	//#################应用场景#####################
	//场景1：1,2,3写在一个函数中
	//场景2：函数调用，1，2在主函数中，3在被调用函数中
	//场景3：封装，1在一块，23在一块；C++中会有

	//场景1 as below
	char from[128];
	char to[128] = { 0 };
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "aabbccdd");
	while (*p1 != '\0') {
		*p2 = *p1;
		p2++;
		p1++;
	}

	printf("to: %s\n", to);
	system("pause");
	return;
}