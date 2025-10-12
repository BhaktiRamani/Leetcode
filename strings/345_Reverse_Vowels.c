// 345. Reverse Vowels of a String
// Easy
// Topics
// premium lock icon
// Companies
// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

// Example 1:

// Input: s = "IceCreAm"

// Output: "AceCreIm"

// Explanation:

// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

// Example 2:

// Input: s = "leetcode"

// Output: "leotcede"

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool vowel_check(char c)
{
  
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    return false;
}

char* reverseVowels2(char* s) {

    int len = strlen(s); 
    char *left = &s[0]; 
    char *right = &s[len - 1];
    char temp;
    while(left < right) 
    {
        printf("1 : Left : %c Right : %c\n" ,*left, *right);
        while(left < right && !vowel_check(*left))
        {
            left++;
            printf("2 : left : %c Right : %c\n",*left, *right);
        }
         while(left < right && !vowel_check(*right))
        {
            right--;
            printf("3 : Left : %c Right : %c\n",*left, *right);
        }
        if(left < right)
        {
            printf("4 : Left : %c Right : %c\n",*left, *right);
            temp = *left; 
            *left = *right; 
            *right = temp; 
            // printf("4 : Left : %c Right : %c\n",*left, *right);
            left++; 
            right--;
        }
        printf("\n");
    }
    return s;
    
}

char* reverseVowels(char* s) {
    int len = strlen(s); 
    char *left = &s[0]; 
    char *right = &s[len - 1];
    char temp;
    
    while(left < right) 
    {
        printf("1 : Left : %c Right : %c\n", *left, *right);
        
        
        while(left < right && !vowel_check(*left))
        {
            left++;
            printf("2 : left : %c Right : %c\n", *left, *right);
        }
        
       
        while(left < right && !vowel_check(*right))
        {
            right--;
            printf("3 : Left : %c Right : %c\n", *left, *right);
        }
        
        
        if(left < right)
        {
            printf("4 : Left : %c Right : %c\n", *left, *right);
            temp = *left; 
            *left = *right; 
            *right = temp; 
            left++; 
            right--;
        }
        printf("\n");
    }
    return s;
}

int main()
{
   char str[] = "IceCreAm"; 

//    char *c = &str[0]; 

//    printf("c : %c , c-- : %c\nstr[7] = %c , str[6] : %c\n", *c, *(++c), str[7], str[6]);

   char *result = reverseVowels2(str); 

   printf("String : %s\n", result); 


   char *ptr = "hey"; 
   int *ptr2 = 10; 

   printf("%ld %ld\n", sizeof(*ptr), sizeof(*ptr2));
}