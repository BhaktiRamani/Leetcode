/*You are given an integer array nums, and an integer k. Let's introduce K-or operation by extending the standard bitwise OR. In K-or, a bit position in the result is set to 1 if at least k numbers in nums have a 1 in that position.

Return the K-or of nums.

 

Example 1:

Input: nums = [7,12,9,8,9,15], k = 4

Output: 9*/
#include<stdio.h>
#include<math.h>
#include<string.h>

int findKOr(int* nums, int numsSize, int k);


int main()
{
    printf("Hello world\n");
    int nums[6] = {7,12,9,8,9,15};
    int k = 4;
    int result = findKOr(nums, 6, k);
    printf("Result is %d\n", result);
}

int findKOr(int* nums, int numsSize, int k) {

    int bit_mask = 0b1;

    int set_bits[k];
    memset(set_bits, 0, sizeof(int)*4);
    printf("%d, %d, %d %d\n", set_bits[0], set_bits[1], set_bits[2], set_bits[3]);


    for(int j = 0; j < k; j++)
    {
        for(int i = 0; i<numsSize; i++)
        {
            if(nums[i] & bit_mask)
            {
                set_bits[j] +=1;
                printf("set bits[%d] = %d\n", j, set_bits[j]);
            }
            
        }

        bit_mask <<=1;
        printf("Bit mask : %d\n", bit_mask);
        printf("%d, %d, %d %d\n", set_bits[0], set_bits[1], set_bits[2], set_bits[3]);
        printf("-------------------------------\n");
    }

    int result = 0;
    for(int index = numsSize; index > 0; index--)
    {

        if(set_bits[numsSize == k])
        {
            result = result + set_bits[numsSize]*(pow(2, numsSize));
            printf("Result : %d\n", result);
        }
        
        
    }
    printf("%d, %d, %d \n", set_bits[0], set_bits[1], set_bits[2]);
    // return result;
    return 0;


    
}