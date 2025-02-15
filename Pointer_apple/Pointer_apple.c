#include <stdio.h>

char *ptr = NULL;

void doSomething1(){
    char x = 0x50;
    ptr = &x;
    printf("value of ptr %d, %d\n", *ptr, x);
    return;
}

void doSomething2(){
    char y = 0x60;
    printf("Value of y : %p\n", &y);
}

int main()
{
    doSomething1();
    doSomething2();
    printf("value of ptr %d\n", *ptr);

    return 0;
}
