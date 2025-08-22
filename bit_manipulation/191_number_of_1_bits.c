// Given a positive integer n, write a function that returns the number of 
// set bits
//  in its binary representation (also known as the Hamming weight).

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

#include <stdio.h>
#include <stdint.h>

#define SET_BIT_COUNT(x) ({ \
    int set_bits = 0; \
    uint32_t mask = 1; \
    int num = x;    \
    for(int i = 0; i<32; i++)   \
    {\
        if(num & (1 << i)) set_bits++;\
    }\
    printf("set_bits %d\n", set_bits);\
})

#define REVERSE_BITS(num) ({ \
   int res = 0;     \
   int bit = 0; \
   for (int i = 0; i < 32; i++) \
   {\   
        bit = num & 1;\
        num = num >> 1;\
        res = res << 1 | bit;\
   }\
   printf("Reverse bits : %d\n", res);\
})

int main()
{
    SET_BIT_COUNT(2147483645);
}

