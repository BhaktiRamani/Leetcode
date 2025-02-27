#include<stdio.h>

int complement(int x)
{
    return ~x;
}
void extract_least_significant_ones_bit()
{
    
}

int main()
{   
    int result = complement(2);
    printf("complement %d\n", result);
}