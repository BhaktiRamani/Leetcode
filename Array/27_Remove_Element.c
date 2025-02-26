// 27. Remove Element
// Easy
// Topics
// Companies
// Hint
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include<stdio.h>



int removeElement(int* nums, int numsSize, int val) {
    
    int *read_ptr = nums;
    int *swap_ptr = nums + 1;
    int size = sizeof(nums)/sizeof(nums[0]);
    int occurance = 0;

    int swap_ptr_position = 1;
    for(int i = 0; i < numsSize; i++)
    {
        printf("\n\nS Read ptr %d Swap ptr %d Swap ptr position %d\n", *read_ptr, *swap_ptr, swap_ptr_position);
        if(*read_ptr == val)
        {
            while(*swap_ptr == val)    swap_ptr++; swap_ptr_position++;
            
            //swap
            *swap_ptr = *swap_ptr ^ *read_ptr;
            *read_ptr = *swap_ptr ^ *read_ptr;
            *swap_ptr = *swap_ptr ^ *read_ptr;
             if(swap_ptr_position == numsSize)    break;
        }
        read_ptr++;
        swap_ptr++;
        swap_ptr_position++;
        printf("E Read ptr %d Swap ptr %d Swap ptr position %d\n", *read_ptr, *swap_ptr, swap_ptr_position);
        for(int j=0; j<numsSize; j++){
            printf("%d  ", nums[j]);
        }
    }
    for(int j=0; j<numsSize; j++){
        if(nums[j] == val)
        {
            printf("_ ");
        }
        else{
            printf("%d  ", nums[j]);
        }
        
    }

    printf("\n");
    return 0;
}

int main()
{
    int arr[8] = {0, 1, 2, 2, 3, 0, 4, 2};
    removeElement(arr, 8, 2);
    // int *read_pointer = arr;
    // int *swap_pointer = arr+1;
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int overflow = 1;

    // for (int i=0 ; i<size && overflow < size; i++){
    //     printf("\nread ptr %d, swap ptr %d\n", *read_pointer, *swap_pointer);
    //     if(*read_pointer == 2){
    //         while(*swap_pointer == 2){
    //             swap_pointer++;
    //             overflow++;
    //         }

    //         if(overflow == size) break;

    //         printf("s read ptr %d, swap ptr %d\n", *read_pointer, *swap_pointer);
    //         // printf("we are in swap\n");
    //         *swap_pointer = *read_pointer ^ *swap_pointer;
    //         *read_pointer = *read_pointer ^ *swap_pointer;
    //         *swap_pointer = *read_pointer ^ *swap_pointer;
    //         printf("s read ptr %d, swap ptr %d\n\n", *read_pointer, *swap_pointer);
    //         for(int j=0; j<size; j++){
    //             printf("%d ", arr[j]);
    //         }

    //     }
    //     read_pointer++;
    //     swap_pointer++;
    //     overflow++;
    // }




    // int result = removeElement1(arr, 8, 2);
    // printf("result = %d\n", result);
}