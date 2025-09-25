
// Code
// Testcase
// Test Result
// Test Result
// 168. Excel Sheet Column Title
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

#include<stdio.h>
#include<stdlib.h>
char* convertToTitle(int columnNumber) {
    
    char* result = malloc(10);

    if(columnNumber > 26)
    {
        int last = columnNumber%26;
        int first = columnNumber/26; 
        result[0] = first + 64;
        result[1] = 64 + last; 
        printf("last : %d , first : %d , result[0] : %d %c , result[1] : %d %c\n", last, first, result[0], result[0], result[1], result[1]);

        printf("last : %d , first : %d\n", last,first);
        result[2] = '\n';
    }
    else{
        int num = columnNumber + 64;
        result[0] = num;
        result[1] = '\n';
    }

    


    return result;
}


int main()
{
    char a = 'A';
    char b = 93;
    printf("%c\n", b);

    char *result = convertToTitle(2); 
    printf("Result : %s\n", result);
}