#include<stdio.h>



struct data{
    int x;
    char y;
    float z;
    int *ptr;
};

int main()
{
    struct data d;
    d.x = 2;
    d.y = 'A';
    d.z = 5.6;
    int x = 10;
    d.ptr = &x;

    printf("d.x     %d\n", d.x);
    printf("d.y     %c\n", d.y);
    printf("d.z     %f\n", d.z);
    printf("d.ptr   %d\n", (*d.ptr));


    struct data *d2;
    d2-> x = 2;
 
    d2 -> y = 'A';
    d2 -> z = 5.6;
    int y = 10;
    // d2 -> ptr = &y;

    printf("d2 -> x     %d\n", d2 -> x);
    printf("d2 -> y     %c\n", d2 -> y);
    printf("d2 -> z     %f\n", d2 -> z);
    // printf("d2 -> ptr   %d\n", (*d2 ->ptr));

}