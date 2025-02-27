#include<stdio.h>

typedef struct val{
    int min;
    int *max;
    char *buffer;
}val_t;

val_t func()
{
    val_t v;
    int value = 109;
    v.min = value;
    int max = 110;
    v.max = &max;
    return v;
}

int main()
{
    val_t vl = func();
    printf("Given value %d and Max value %d \n", vl.min, *vl.max);

    // Pointer to a structure
    val_t *v = &vl;
    v -> min = 120;
    int max = 130;
    v -> max = &max;
    //v -> buffer[0] = 'A';
    // char arr[5] = {'B', 'C', 'D'};
    // v -> buffer = arr;
    char *str = "Hello";
    v -> buffer = str;
    printf("v -> min = %d v -> max = %d v -> buffer[0] = %c \n", v -> min, *v->max, v -> buffer[0]);

}