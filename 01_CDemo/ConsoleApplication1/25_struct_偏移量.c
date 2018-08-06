#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

//struct定义了之后就不应该对元素的修改，元素的增减或者数据类型的变化都会造成偏移量的变化
typedef struct AdTeacher {
	char name[64];
	int age;
	int p;
	char *pname2;
} AdTeacher;

int main254() {
	int i = 0;
	AdTeacher t1;
	AdTeacher *p = NULL;
	p = &t1;
	//p = p + 100;

	{
		//int offsize1 = (int)&(p->age);//age的地址=p+age偏移量
		int offsize1= (int)&(p->age)-(int)p;//计算age的偏移量
		int offsize2 = (int)&(((AdTeacher*)0)->age);
		printf("offsized1:%d \n", offsize1);
		printf("offsized2:%d \n", offsize2);
	}

	printf("hello..../n");
	system("pause");
	return;
}