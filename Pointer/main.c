//poiter to a funtion that pointes to a fnciton pointer that returns a pointer

#include<stdio.h>
int sum(int a, int b);
int *subtract(int *a, int*b , int *c);

int main()
{
    int  (*sum_func_ptr)(int, int);
    sum_func_ptr = &sum;

    int summ = (*sum_func_ptr)(2 ,3);
    printf("summ = %d\n", summ);

    int x = 5;
    int y = 3;
    int z = 0;
    int (*subtract_func_ptr)(int *a, int *b, int *c);
    subtract_func_ptr = &subtract;

    int *subtract = (*subtract_func_ptr)(&x, &y, &z);
    printf("subtract = %d\n", *subtract);

}


int *subtract(int *a, int*b , int *c)
{
    *c = *a - *b;
    return c;
}


int sum(int a, int b)
{
    return a+b;
}