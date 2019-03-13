#include "stdafx.h"
#include "iostream"

using namespace std;

void main32() {
	//general reference
	int a = 10;
	int &b = a;
	printf("b:%d\n", b);

	//const reference
	int x = 20;
	//const ref make the variable as read-only,
	//the value of x couldn't modified via y
	const int &y = x;

	//two scenarios of const ref
	//1-> initial const ref by variable
	{
		int x1 = 30;
		const int &y1 = x1;
	}
	//2-> initial const ref by literals
	{
		const int a = 40;//compiler will put the variable 'a' into sympol table

		//literals are not left value, no memory address.
		//int &m = 41; //error - > initial value of reference to non - const must be an lvalue
		const int &m = 43;//compiler will assign memory to const ref m

		//conclusion -> general ref can't initial by literals, but const ref can.
	}
}

struct Teacher {
	int age;
	char name[64];
};

//void printTeacher(const Teacher *const myt)
//the const ref almost be used with formal para, to empower it read-only attribute.
void printTeacher(const Teacher &myt) {

	//const ref assure the formal parameter is read only.
	//myt.age = 36; //error -> expression must be a modifiable lvalue

	printf("myt.age:%d\n", myt.age);
}

int main03() {
	Teacher t1;
	t1.age = 36;

	printTeacher(t1);

	cout << "hello..." << endl;
	system("pause");
	return 0;
}