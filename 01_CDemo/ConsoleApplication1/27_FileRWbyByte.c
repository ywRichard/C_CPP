#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
//**************************
//1、按字符读写文件
void myfputc() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//统一的用45度，兼容unix和windows系统
	char a[27] = "abcdqwer";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	for (i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	fclose(fp);
}
void myfgetc() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//统一的用45度，兼容unix和windows系统
	char a[27] = "abcdqwer";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	while (!feof(fp))
	{
		char tempc = fgetc(fp);
		printf("%c", tempc);
	}
	printf("\n");
	if (fp != NULL)
	{
		fclose(fp);
	}
}

//****************************
//2、按行读写文件
void myfputs() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//统一的用45度，兼容unix和windows系统
	char a[27] = "asasdasdasd";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");

	fputs(a, fp);

	if (fp != NULL)
	{
		fclose(fp);
	}
}
void myfgets() {
	int i = 0;
	FILE *fp = NULL;
	char *filename = "c:/2.txt";//统一的用45度，兼容unix和windows系统
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err:%d \n");
		return;
	}
	printf("open successful\n");
	char buf[1024];
	//1、C函数库会 一行一行 的copy数据到buf指针所指的内存空间中，并且变成C风格的字符串
	//2、把\n也copy到我们的地址中

	//3、内存打包技术（内存首地址 + 内存长度）
	while (!feof(fp))
	{
		char *p = fgets(buf, 2014, fp);
		if (p == NULL)
		{
			goto End;
		}
		printf("%s", buf);
	}
	printf("\n");

End:
	if (fp != NULL)
	{
		fclose(fp);
	}
}

//****************************
//3、按块读写文件
typedef struct Teacher {
	char name[20];
	int age;
} Teacher;

void myfwrite() {
	int i = 0;
	Teacher myTeacher[3];
	for (i = 0; i < 3; i++)
	{
		sprintf(myTeacher[i].name, "%d%d%d", i + 1, i + 1, i + 1);
		myTeacher[i].age = i + 1;
	}

	FILE *fp = NULL;
	char *fileName = "c:/test/3.data";
	fp = fopen(fileName, "wb");
	if (fp == NULL)
	{
		printf("create file failed\n");
		return;
	}
	int myCount = 0;
	for (i = 0; i < 3; i++)
	{
		//内存打包技术，内存块开始地址 + 写入内存长度
		/*_In_reads_bytes_(_ElementSize * _ElementCount) void const* _Buffer,//内存块开始的地址
			_In_     size_t      _ElementSize,//元素的大小
			_In_     size_t      _ElementCount,//写入元素的个数，即写多少次
			_Inout_  FILE*       _Stream*///写入到文件指针所指向的文件中
		myCount = fwrite(&myTeacher[i], sizeof(myTeacher), 1, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
	}
}

void myfread() {
	int i = 0;
	Teacher myTeacher[3];

	FILE *fp = NULL;
	char *fileName = "c:/test/3.data";
	fp = fopen(fileName, "rb");
	if (fp == NULL)
	{
		printf("open file failed\n");
		return;
	}
	int myCount = 0;
	for (i = 0; i < 3; i++)
	{
		//myCount = fwrite(&myTeacher[i], sizeof(Teacher), 1, fp);
		myCount = fread(&myTeacher[i], sizeof(Teacher), 1, fp);
	}

	for (i = 0; i < 3; i++)
	{
		printf("name:%s, age:%d\n", myTeacher[i].name, myTeacher[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}



int main() {
	//1、按字符读写文件
	//myfputc();
	//myfgetc();

	//2、按行读写文件
	//myfputs();
	//myfgets();

	//3、按块读写文件
	//myfwrite();
	myfread();

	printf("hello.....\n");
	system("pause");
	return;
}