#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int ItoB(unsigned int value);
int func(void);
void ques_1();
void ques_2();
void ques_8();
unsigned int reverse_bits(unsigned int);
char *get_bitarray(unsigned int, char *);
char *set_bit(char *myarray, unsigned int index, unsigned int array_size);
char *clear_bit(char *myarray, unsigned int index, unsigned int array_size);
char *assign_bit(char *myarray, unsigned int index, int value, unsigned int array_size);
int test_bit(char *myarray, unsigned int index, unsigned int array_size);

int main05()
{
    unsigned int input = 10;
    // printf("%d to Binary:", input);
    // ItoB(input);
    // printf("\n Finished\n");

    // ques_1();
    // ques_2();
    // ques_4();
    // ques_7();
    // ques_8();

    //5.3 test
    //0xf1: 10001111
    // unsigned int value = 13; //1011
    // printf("\n    value:");
    // ItoB(value);
    // printf("\n    reverse_bits:");
    // ItoB(reverse_bits(value));
    // printf("\n");

    // //5.4 test
    // unsigned int data = 0xfe;
    // char myarray[1024] = {0};
    // printf("myarray:%s\n", get_bitarray(data, myarray));
    // unsigned int array_size = strlen(myarray);
    // //set index bit to 1
    // printf("set_bit:%s\n", set_bit(myarray, 0, array_size));
    // //clear the index bit to 0
    // printf("clear_bit:%s\n", clear_bit(myarray, 1, array_size));
    // //value:0, index bit:0; value:1, index bit:1;
    // printf("assign_bit:%s\n", assign_bit(myarray, 2, 0, array_size));
    // //if the value of index bit is 0, return 0; otherwise return 1;
    // printf("test_bit:%d\n", test_bit(myarray, 3, array_size));

    //5.5 test
    //begin=13, end =9
    int begin=13, end=9;
    int nonzero_num=begin-end+1;
    short unsigned int temp = ~0;
    temp<<=16 - nonzero_num;
    temp>>=16 - begin;
    char myarray[sizeof(temp)]={0};
    printf("myarray:%s\n", get_bitarray(temp, myarray));
    printf("myarray length:%lu\n", strlen(myarray));

    return 0;
}

//printf a interge as binary format
int ItoB(unsigned int value)
{
    for (; value != 0; value = value >> 1)
    {
        // printf("%d", value % 2);//version_1
        printf("%d", value & 1); //version_2
    }

    return 0;
}
void ques_1()
{
    printf("+++++++question_1++++++++");
    // double a = (25.0/10);
    // printf("(25/10):%f\n",25.0/10);
    // printf("(25/10):%f\n",25/10);
    // printf("(25.0/10):%f\n",25.0/10);
}
int func(void)
{
    static int count = 1;
    return ++count;
}
void ques_2()
{
    int answer;
    //2.1, answer = -2
    // int temp = func()*func();
    // printf("temp %d\n",temp);
    // answer=func()-temp;// -2

    //2.2 answer = -10
    answer = func() - func() * func();
    printf("+++++++question_2++++++++");
    printf("answer:%d \n", answer); // -10
}
//time spent almost same
void ques_4()
{
    int a = 2, b = 4, c = 15, i = 0;
    clock_t begin = clock();
    if (a < 3) //end - begin <= 3
    {
        i = b + 1;
    }
    else
    {
        i = c + 1;
    }
    // i = a < 3 ? b + 1 : c + 1;// end - begin<=3
    clock_t end = clock();
    printf("execution time:%lu\n", end - begin);
    double time_spent = (end - begin) / CLOCKS_PER_SEC; //count spent seconds

    // time_t curtime, curtime1;
    // time(&curtime);
    // printf("curtime:%s\n", ctime(&curtime));

    // time(&curtime1);
    // double result = difftime(curtime1, curtime);

    // time_t temp = time(NULL);
    // printf("temp:%ld\n", temp / 3600); //count the hours from Epoch to present day
}

void ques_7()
{
    int a = 20;
    // if (1 <= a <= 10)
    // {
    //     printf("in range");
    // }
    // else
    // {
    //     printf("out of range");
    // }
}

void ques_8()
{
    int non_zero = 0;
    int myarray[] = {1, 2, 3, 4};
    int array_size = sizeof(myarray) / sizeof(int);
    for (int i = 0; i < array_size; i += 1)
    {
        non_zero += myarray[i];
        printf("non_zero%d:%d\n", i, non_zero);
    }
    printf("non_zero:%d\n", non_zero);
}

unsigned int reverse_bits(unsigned int value)
{
    unsigned int result = 0;
    for (int i = 1; i != 0; i <<= 1)
    {
        result <<= 1;
        if (value & 1)
            result |= 1;
        value >>= 1;
    }

    return result;
}

char *get_bitarray(unsigned int data, char *array)
{
    char tmp[4];
    int count = 0;
    for (; data != 0; data >>= 1)
    {
        sprintf(tmp, "%d", data & 1);
        strncat(array, tmp, 1);
    }

    return array;
}
char *set_bit(char *myarray, unsigned int index, unsigned int array_size)
{
    if (index >= array_size)
    {
        printf("func set_bit() index out of array size\n");
        return NULL;
    }
    myarray[index] = '1';
    return myarray;
}
char *clear_bit(char *myarray, unsigned int index, unsigned int array_size)
{
    if (index >= array_size)
    {
        printf("func set_bit() index out of array size\n");
        return NULL;
    }
    myarray[index] = '0';
    return myarray;
}
char *assign_bit(char *myarray, unsigned int index, int value, unsigned int array_size)
{
    if (index >= array_size)
    {
        printf("func set_bit() index out of array size\n");
        return NULL;
    }
    myarray[index] = value != 0 ? '1' : '0';
    return myarray;
}
int test_bit(char *myarray, unsigned int index, unsigned int array_size)
{
    if (index >= array_size)
    {
        printf("func set_bit() index out of array size\n");
        return -1;
    }
    printf("\n");
    
    return myarray[index] != '0' ? 1 : 0;
}
