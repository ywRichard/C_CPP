#include "stdafx.h"
#include "iostream"

using namespace std;

struct Teacher {
	int age;
	char name[10];
};


// reference on complex data type
void printfT1(Teacher *pT) {
	pT->age = 10;
}

void printfT2(Teacher &pT) {
	pT.age = 33;
}

void printfT3(Teacher pT) {
	cout << pT.age << endl;
	pT.age = 45;
}

void main031(){
	Teacher t1;
	t1.age = 35;

	printfT1(&t1);

	printfT2(t1);//pT is a alias of t1
	printf("t1.age:%d \n",t1.age);//35

	printfT3(t1);//pT is formal parameter, the data is copied from t1 to pT ==> pT = t1
	printf("t1.age:%d \n", t1.age);//35
}