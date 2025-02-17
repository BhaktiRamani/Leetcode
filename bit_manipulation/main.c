// Problem - 1 : Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and
// j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You
// can assume that the bits j through i have enough space to fit all of M. That is, if
//  M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for
// example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
// EXAMPLE
// Input:
// N = 10000000000,
//  M = 10011, 
// i = 2, j = 6
// Output: N = 10001001100

#include<stdio.h>
#include<stdint.h>

#define DECI_TO_BIN(num) ({ \
    int n = num;    \
    int divisor = 2;    \
    int remainder = 0;  \
    int quotient = 0;   \
    int bin_arr[8]; \
    int i = 0; \
    while(n > 0) \
    {\
        remainder = n % divisor; \
        bin_arr[i] = remainder; \
        i++; \
        n = n / divisor; \
    }\
    for(int j = 8; j > 0; j--)\
    {\
        printf("%d ", bin_arr[j]);\
    }\
    printf("\n"); \
})




int main()
{
    DECI_TO_BIN(2);
  
  uint32_t N = 10000000000;
  uint32_t M = 10011;
  int i = 2;
  int j = 6;

  // Step 1: Create a mask to clear bits from position i to j in N
  uint32_t allOnes = ~0;  // All bits set to 1
  uint32_t left = allOnes << (j + 1);    // Set all bits to the left of position j to 1
  uint32_t right = (1 << i) - 1;         // Set all bits to the right of position i to 1
  uint32_t mask = left | right;          // Mask with 0s between i and j, and 1s elsewhere

  // Step 2: Clear the bits from position i to j in N
  N = N & mask;
  printf("N %u\n M %u\n",N, (M << i));
  M = M << i;
  N = N | (M);
  printf("N %u\n M %u\n",N, (M << i));
}