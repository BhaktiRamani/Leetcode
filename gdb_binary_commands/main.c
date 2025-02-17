// Simple Problem to try gdb commands and binary debugging

#include <stdio.h>

int global_var = 32;

void my_func()
{
    printf("my_func\n");
}

int main()
{   
    char*str = "Hello";
    printf("Hello World\n");
    my_func();
}