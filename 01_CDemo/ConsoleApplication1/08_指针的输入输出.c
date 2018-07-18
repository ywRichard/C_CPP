#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int getMem41(char **myP1/*out*/, int *myLen1/*out*/, char **myP2/*out*/, int *myLen2/*out*/) {
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

//通过return得到修改结果的指针
char * getMem42(int num) {
	int ret = 0;
	char *tmp1;

	tmp1 = (char *)malloc(num);
	strcpy(tmp1, "113223");

	return tmp1;
}

void main08() {
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