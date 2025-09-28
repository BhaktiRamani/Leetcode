// 1470. Shuffle the Array
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

// Example 1:

// Input: nums = [2,5,1,3,4,7], n = 3
// Output: [2,3,5,4,1,7] 
// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
// Example 2:

// Input: nums = [1,2,3,4,4,3,2,1], n = 4
// Output: [1,4,2,3,3,2,4,1]
// Example 3:

// Input: nums = [1,1,2,2], n = 2
// Output: [1,2,1,2]

#include<stdio.h>

void print_array(int *arr, int size)
{
    printf("------------ \n");
    for(int i = 0; i < size; i++)
    {
        printf(" [%d] : %d\n", i , arr[i]);
    }
    printf("------------\n");
}

int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    int first_arr[n]; 
    int sec_arr[n]; 
    int* result = (int*)malloc(numsSize * sizeof(int));

    for(int i = 0; i< 2*n; i++)
    {
        
        // printf("%d : %d\n", i, nums[i]);
        if(i < n)
        {
            //  printf("First arr %d : %d\n", i, nums[i]);
             first_arr[i] = nums[i];
            }
            else{
                sec_arr[i-n] = nums[i];
                // printf("Sec arr %d : %d %d\n", i -n, nums[i], sec_arr[i-n]);
         }
        //  printf("\n");
    }
    // printf("First arr : \n");
    // print_array(first_arr, n);
    // printf("Second arr : \n");
    // print_array(sec_arr, n);
    int i = 0; 
    int first_c = 0;
    int sec_c = 0;

    while(i < 2*n)
    {
        if(i%2 == 0)
        {
            result[i] = first_arr[first_c];
            first_c++;
            // printf("first   %d : %d %d\n", i, first_arr[i],result[i]);
        }
        else{
            result[i] = sec_arr[sec_c];
            sec_c++;
            // printf("second  %d : %d %d\n", i, sec_arr[i],result[i]);
        }
        i++;

    }
     *returnSize = numsSize; 
    return result;
}


int* shuffle2(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int first_c = 0;
    int sec_c = n;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            result[i] = nums[first_c++];
        } else {
            result[i] = nums[sec_c++];
        }
    }

    *returnSize = numsSize;  // <--- important!
    return result;
}


int main()
{
    int nums[8] = {1,2,3,4,4,3,2,1};

    print_array(nums, 8);

    int returnArr[8];
    shuffle(nums, 8, 4, returnArr);

    print_array(returnArr, 8);


}

