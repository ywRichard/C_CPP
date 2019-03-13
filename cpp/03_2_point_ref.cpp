#include "stdafx.h"
#include "iostream"

using namespace std;

struct Teacher {
	int age;
	char name[10];
};

//1. second level pointer in C
int getTeacher(Teacher **p) {
	if (p == NULL)
		return -1;

	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher));
	if (tmp == NULL)
		return -2;

	tmp->age = 33;
	*p = tmp;
	return 1;
}

//2. pointer reference
int getTeacher2(Teacher* &myp) {
	if (myp = NULL)
		return -1;

	myp = (Teacher *)malloc(sizeof(Teacher));
	if (myp == NULL)
		return -2;
	
	myp->age = 36;
	return 1;
}

void FreeTeacher(Teacher *pT1) {
	if (pT1 == NULL)
		return;
	free(pT1);
	return;
}

int main032() {
	Teacher *pT1 = NULL;
	cout << "run the point of reference" << endl;

	//1. second level pointer in C
	getTeacher(&pT1);
	cout << "age:" << pT1->age << endl;
	FreeTeacher(pT1);

	//2. cpp, the pointer reference
	getTeacher2(pT1);
	cout << "age:" << pT1->age << endl;
	FreeTeacher(pT1);

	system("pause");

	return 0;
}