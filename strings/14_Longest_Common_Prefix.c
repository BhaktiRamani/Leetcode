// 14. Longest Common Prefix
// Easy
// Topics
// Companies
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""

#include<stdio.h>
#include<string.h>

char result[5] = " ";

char* longestCommonPrefix(char** strs, int strsSize) {
    
    for(int i = 0; i < strsSize; i++)
    {

        printf("strs[0][i] = %c  \n", strs[0][i]);
        printf("strs[0][i] = %c  \n", strs[1][i]);
        printf("strs[0][i] = %c  \n", strs[2][i]);
        if(((strs[0][i]) == strs[1][i]) && (strs[0][0]) == (strs[2][i]))
        {
            result[i] = strs[0][i];
            printf("%s \n", result);
        }
        else
        {
            return result;
            break;
            
        }

    }
    printf("%s \n", result);
    return result;

    
}


int main()
{
    // other way to initialize strings - 
    // char strs[NUMBER_OF_STRINGS][STRING_LENGTH + 1] 
    // and then assign with strncpy 

    // array of strings so the array type is string type (which is char*)
    
    char* str[3] = {"flower", "flow", "flight"};
    printf("%c\n", str[0][0]);

    char* result = longestCommonPrefix(str, 3);
    printf("Result = %s\n", result);


}