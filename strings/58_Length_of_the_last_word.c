// 58. Length of Last Word
// Easy
// Topics
// premium lock icon
// Companies
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.


#include<stdio.h>
#include<string.h>

int lengthOfLastWord(char* s) {
     
    int len = strlen(s);
    char *c = &s[len - 1];
    // printf("*c : %c\n", *c);
    int result = 0;
    while(*c == ' ')
    {
        // printf(" Loop 1 - *c : %c\n", *c);
        c--;
    }
    
    // while(*c != ' ' && c>=s)
    // c>=s condition for only single worded strings, so that we don't go infinately because space is not available. 
    while (c >= s && *c != ' ') 
    {
        // printf(" Loop 2 - *c : %c\n", *c);
        result += 1; 
        c--;
    }
    printf("result : %d\n", result);
    return result;
}
    



int main()
{   
    int result = lengthOfLastWord("   fly me   to   the moon ");
    printf("Result : %d\n", result);
}