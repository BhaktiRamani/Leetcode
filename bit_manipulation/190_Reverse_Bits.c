// 190. Reverse Bits
// Easy
// Topics
// premium lock icon
// Companies
// Reverse bits of a given 32 bits unsigned integer.

// Note:

// Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation.
 

// Example 1:

// Input: n = 43261596

// Output: 964176192

// Explanation:

// Integer	Binary
// 43261596	00000010100101000001111010011100
// 964176192	00111001011110000010100101000000
// Example 2:

// Input: n = 2147483644

// Output: 1073741822

// Explanation:

// Integer	Binary
// 2147483644	01111111111111111111111111111100
// 1073741822	00111111111111111111111111111110


#include<stdio.h>

int countbits(int num)
{
    unsigned int count = 0;
    while(num)
    {
        count+=1;
        num>>=1;
    }
    return count;
}

#define REVERSE_BITS(x) ({ \
   int res = 0;\
   int bit = 0; \
   int num = x;\
   for (int i = 0; i < 32; i++)   \
   {\
        bit = num & 1;\
        num = num >> 1;\
        res = res << 1 | bit;\
   }\
   printf("Reverse bits : %d\n", res);\
})

int main()
{
   int num = 2147483644;
   int res = 0;
   int bit = 0;
   for (int i = 0; i < 32; i++)
   {    
        bit = num & 1;
        num = num >> 1;
        printf("Res 1 : %d\n", bit);
        res = res << 1 | bit;
        printf("Res 2 : %d %d\n", res, num);
        printf("\n");
   }
   printf("%d\n", res);
   
   REVERSE_BITS(2147483644);

   return res;

}

