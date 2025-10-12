// 28. Find the Index of the First Occurrence in a String
// Easy
// Topics
// premium lock icon
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

int strStr2(char* haystack, char* needle) {
    char *ptr1 = &haystack[0]; 
    char *ptr2 = &needle[0];

    int cnt = 0;
    int p_cnt = cnt;
    while(*ptr1 != *ptr2 && *ptr1 != '\0')
    {
        printf("1 : *ptr1 : %c , *ptr2 : %c\n", *ptr1, *ptr2);
        cnt++;
        ptr1++;
    }
    printf("\n");
    while( *ptr1 == *ptr2 && *ptr1 != '\0')
    {
        printf("2 : *ptr1 : %c , *ptr2 : %c\n", *ptr1, *ptr2);
        p_cnt++;
        ptr1++;
        ptr2++;
    }
    printf("\n");
    if(*ptr1 != '\0')
    {
        ptr1--;
        cnt = p_cnt;
        ptr2 = &needle[0];
    }
    while( *ptr1 == *ptr2 && *ptr1 != '\0')
    {
        printf("2 : *ptr1 : %c , *ptr2 : %c\n", *ptr1, *ptr2);
        ptr1++;
        ptr2++;
    }
  
    printf("\n");
    // printf("*ptr1 : %c , *ptr2 : %c\n", *ptr1, *ptr2);

    if(*ptr2 == '\0')
    {
        return cnt -1 ;
    }
    return -1;
    
    
}

int strStr3(char* haystack, char* needle) 
{
    char *ptr1 = &haystack[0]; 
    char *ptr2 = &needle[0];
    int cnt = 0;
    int j = 0;
    int tmp = 0;
    for(int i = 0; i < strlen(haystack); i++)
    {
        cnt++;
        
        printf("1 : haystack : %c , needle : %c\n\n", haystack[i], needle[j]);
        if(haystack[i] == needle[j])
        {
  
            tmp = i;
            int j = 0; 
            while(haystack[i] == needle[j])
            {
                printf("2 : haystack : %c , needle : %c\n\n", haystack[i], needle[j]);
                if(haystack[i] == '\0')
                {
                    return cnt;
                }
                i++;
                j++;
            }
            printf("3 : haystack : %c , needle : %c\n\n", haystack[i], needle[j]);
            if(needle[j] == '\0')
            {
                return cnt -1;
            }
            else{
                printf("i : %d\n", i);
                i = tmp;
                cnt ++;
            }
           

        }
    }
    return -1;
}

int strStr(char* haystack, char* needle) 
{
    if(strlen(needle) == 0)
    {
        return 0;
    }

    for(int i = 0; i < strlen(haystack) - strlen(needle) + 1; i++)
    {
        for(int j = 0; j < strlen(needle); j++)
        {
            if(j == strlen(needle) -1)
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    int result = strStr("mississippi", "pi");
    printf("Result : %d\n", result);
}