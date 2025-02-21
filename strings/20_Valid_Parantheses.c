// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define BOOL(x) ((x==0) ? "false" : "true")


bool isValid(char* s) {
    int str_len = strlen(s);

    printf("Str_len %d\n", str_len);

    if(str_len % 2 != 0) return false;

    int same = 0;
    for(int i = 0, j = 0; i < str_len/2; i++, j=j+2)
    {
        printf("here s[i] %c s[i+1] %c (int)s[i] %d  (int)s[i+1] %d  i %d str_len/2 %d\n", s[j], s[j+1], (int)s[j], (int)s[j+1], j, str_len/2);
        if((int)s[j] == ((int)s[j+1] + 1))
        {
            same += 1;
        }
    }

    printf("same %d\n", same);
    if(same == str_len/2)   return true;
    return false;


}

int main()
{
    char c = '{';
    char d = '}';
    int a = c;
    printf("%d  %d\n", a, (int)d);

    char str[6] = {'(', ')', '{', '}', '[', ']'};
    bool status = isValid(str);
    
    printf("str %s\n", BOOL(status));
}