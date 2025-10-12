// 509. Fibonacci Number
// Easy
// Topics
// premium lock icon
// Companies
// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
#include<stdio.h>

int result = 0;
int fib(int n){
   
    int f1 = n - 1; 
    int f2 = n - 2 ; 
    printf("n : %d f1 : %d , f2 : %d, result : %d\n", n, f1, f2, result);
    if(f1 > 1) {result = result + fib(f1);}
    if(f2 > 1) {result = result + fib(f2);}

    if(f2 == 1){result = result + 1;}
    if(f1 == 1 && f2 == 1) {printf("1\n");return 2;}
    if(f1 == 0 && f2 == 0) {printf("2\n");return 0;} 
    if(f1 == 1 && f2 == 0) {printf("3\n");return 1;} 
    printf("Result : %d\n", result);
    printf("\n");

    return result;
}

int main()
{
    int res = fib(4);
    printf("Res : %d\n", res);
    return 0;
}