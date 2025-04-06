#include<stdio.h>

int main()
{
    int a = 2;
    int b = 3;
    int result;
    int carry = 1;
    
    
    while(carry != 0)
    {
        carry = 0;
        result = a ^ b;
        carry = (a&b) << 1;
        a = result;
        b = carry;
    }
    printf("Result %d, carry %d\n", result, carry);
}