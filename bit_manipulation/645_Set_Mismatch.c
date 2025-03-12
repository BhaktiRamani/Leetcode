// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array. 

// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1]
// Output: [1,2]

#include <stdio.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int rep_num = 0;
    for(int i = 0; i< numsSize; i++)
    {
        rep_num = rep_num ^ nums[i];
    }
    for(int i = 1; i< numsSize; i++)
    {
        rep_num = rep_num ^ i;
    }
    
    nums[0] = rep_num;
    nums[1] = rep_num + 1;
    return nums;
}


int main()  
{
    int nums[4] = {1, 2, 2, 4};
    int *result = findErrorNums(nums,3, nums);
    printf("result[0] = %d  result[1]  = %d\n", result[0], result[1]);

}