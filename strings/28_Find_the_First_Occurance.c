// 28. Find the Index of the First Occurrence in a String
// Easy
// Topics
// Companies
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

#include<stdio.h>
#include<string.h>

int strStr(char* haystack, char* needle) {
    char *ptr_h = haystack;
    int count = 0;
    int result = 0;
    
    // char* p = haystack;
    // char *n = needle;

    // int index = 0;
    // while(*p == *n)
    // {
    //     p++;
    //     n++;
    //     index++;
    // }

    // if(*n == '\0')
    // {
    //     return index;
    // }
    // else{
    //     return -1;
    // }

    for(int i = 0; i< strlen(haystack); i++)
    {
        printf("Haystack %c Needle %c Count %d Ptr_h %c\n", haystack[i], needle[count], count, *ptr_h);
        if(haystack[i] == needle[count])
        {
            count++;
            result = i;
            ptr_h++;
            printf("Inside : %d Haystack %c Needle %c Count %d Ptr_h %c\n", i, haystack[i], needle[count], count,*ptr_h);
            while((*ptr_h == needle[count]) && (count <= strlen(needle))) 
            {
                ptr_h++; 
                count++;
                printf("In : Haystack %c Needle %c Count %d Ptr_h %c\n", haystack[i], needle[count], count,*ptr_h);
                if(needle[count] == '\0') return i;
            }
        }
        ptr_h++;

    }


    return -1;
    
    
}

int main()
{
    char *str1 = "sadbutsad";
    char *str2 = "sad";
    int occurance = strStr(str1, str2);
    printf("Occurance %d\n", occurance);
}