// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3


#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
   int rep_num = 0;
   for(int i = 0; i<numsSize; i++)
   {
        rep_num = rep_num ^ nums[i];
   } 
   for(int i = 1; i< numsSize; i++)
   {
        rep_num = rep_num ^ i;
   }
   return rep_num;
}
int main()
{
    int nums[4] = {1, 2, 3, 3};
    int result = findDuplicate(nums, 4);
    printf("Result = %d\n", result);
}