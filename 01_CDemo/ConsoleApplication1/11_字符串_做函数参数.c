#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void main111() {
	char a[] = "i am a student";
	char b[64];
	int i = 0;

	//实现字符串的copy
	for (i = 0; i < *(a + i) != '\0'; i++)//字符串以'\0'结尾
	{
		//取出(a + i)指向的内存空间的值再赋值给(b + i)指向的内存空间
		*(b + i) = *(a + i);
	}
	//0没有copy到b的buf中
	b[i] = '\0';//重要

	printf("a:%s \n", a);
	printf("b:%s \n", b);

	system("pause");
	return;
}

//字符串copy函数技术推演
//形参from, to的值在不停的变化, 不断的修改from和to的指向
void cpy_str0(char *from, char *to) {
	for (; *from != '\0'; from++, to++)
	{
		*to = *from;
	}
	*to = '\0';//构造c风格的字符串
}

//优化1
//* 和 ++操作的优先级 ++优先级高
void cpy_str1(char *from, char *to) {
	for (; *from != '\0';)
	{
		*to++ = *from++; //先 *to=*from; 再from++, to++
	}
	*to = '\0';
}

//优化2
void cpy_str2(char *from, char *to) {
	while ((*to = *from) != '\0') //表达式(*to = *from)的值等于*from的值
	{
		from++;
		to++;
	}
}

//优化3
void cpy_str3(char *from, char *to) {
	//1、执行 *to=*from，表达式(*to++ = *from++)==*from
	//2、执行 from++, to++
	//3、判断(*to++ = *from++) ！= '\0'
	while ((*to++ = *from++) != '\0')
	{
		;
	}
}

//优化4
//这个函数参数的用法，主调用函数分配内存，供被调用函数使用
void cpy_str4(char *from, char *to) {
	while ((*to++ = *from++))
	{
		;
	}
}

//优化5
//这个函数参数的用法，主调用函数分配内存，供被调用函数使用
int cpy_str5(char *from, char *to) {
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while ((*to++ = *from++));
}

void main112() {
	char *from = "abcd";
	char buf[100];
	cpy_str0(from, buf);
	printf("buf0:%s \n", buf);

	cpy_str1("efgh", buf);
	printf("buf1:%s \n", buf);

	cpy_str2("qwer", buf);
	printf("buf2:%s \n", buf);

	cpy_str3("rtyu", buf);
	printf("buf4:%s \n", buf);

	cpy_str4("dfgh", buf);
	printf("buf4:%s \n", buf);

	{
		//test the scenario of what copt a string const to a char array but the size of char array is less then string const.
		//the result is the size of array doesn't changed, but the string length of the variable is changed.
		char testBuf[1];
		printf("sizeof(testBuf):%d\n", sizeof(testBuf));
		printf("strlen(testBuf):%d\n", strlen(testBuf));
		cpy_str4("dfgh", testBuf);
		printf("testBuf:%s \n", testBuf);
		printf("sizeof(testBuf):%d\n", sizeof(testBuf));
		printf("strlen(testBuf):%d\n", strlen(testBuf));
	}

	{
		//错误案例
		char *myto = NULL;//只是定义了指针变量，但是并没有分配内存；*(0x00000000),NULL的内存块是系统保护的，不能够被更改。
		//cpy_str4(from, myto);//直接调用myto，程序会抛异常。
		int ret = 0;
		ret = cpy_str5(from, myto);
		if (ret != 0)
		{
			printf("func_cpy_str5 err:%d", ret);
			return ret;
		}
	}

	system("pause");
	return;
}

//优化6
//不要轻易改变形参的值，引入辅助指针变量来把形参接过去操作
int cpy_str6_good(char *from, char *to) {
	char *tmpFrom = from;
	char *tmpTo = to;
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*tmpTo++ = *tmpFrom++);
	printf("from:%s \n", from);
}
int cpy_str6_err(char *from, char *to) {

	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*to++ = *from++);
	printf("from:%s \n", from);
}

void main113() {
	//为什么字符串后面会出现乱码？
	char txtBuf[] = { 'a','c','r','f' };
	char *txtP = txtBuf;
	printf("txtPValue:%s\n", txtP);
	printf("txtPAddress:%x\n", &txtP);
	strcpy(txtP, txtBuf);
	printf("txtStrValue:%s\n", txtP);

	char *from = "abcd";

	char buf1[100];
	printf("cpy_str6_err start\n");
	cpy_str6_err(from, buf1);
	printf("cpy_str6_err finish\n");
	printf("buf1:%s \n", buf1);

	char buf2[100];
	printf("cpy_str6_err start\n");
	cpy_str6_good(from, buf2);
	printf("cpy_str6_err finish\n");
	printf("buf2:%s \n", buf2);

	printf("pause");
	return;
}