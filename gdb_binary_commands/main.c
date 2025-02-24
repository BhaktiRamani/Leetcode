// Simple Problem to try gdb commands and binary debugging

#include <stdio.h>

int global_var = 32;

void my_func()
{
    printf("my_func\n");
}

int main()
{   

    int i = 9;
    // prints a stack fram pointer for this 
    printf(" i & frame pointer = %p %p \n", &i, __builtin_frame_address(0));

    char*str = "Hello";
    printf("Hello World\n");
    my_func();
    int x = 0;
    for(int i = 0; i < 5; i++)
    {
         x = i;
    }
    printf("x = %d\n", x);
    printf("Hello World\n");
    
}