// You are given two strings s and t.

// String t is generated by random shuffling string s and then add one more letter at a random position.

// Return the letter that was added to t.

 

// Example 1:

// Input: s = "abcd", t = "abcde"
// Output: "e"
// Explanation: 'e' is the letter that was added.
// Example 2:

// Input: s = "", t = "y"
// Output: "y"

#include<stdio.h>
#include<stdint.h>

char findTheDifference(char* s, char* t) {
    while(*s == *t)
    {   
        s++;
        t++;
    }
    
    return *t;
}
int main()
{
    char *s = "bhakti";
    char *t = "bhaktir";
  
    char r = findTheDifference(s, t);
    printf("result = %c\n", r);
}


