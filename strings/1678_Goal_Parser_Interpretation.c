// 1678. Goal Parser Interpretation
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

// Given the string command, return the Goal Parser's interpretation of command.

 

// Example 1:

// Input: command = "G()(al)"
// Output: "Goal"
// Explanation: The Goal Parser interprets the command as follows:
// G -> G
// () -> o
// (al) -> al
// The final concatenated result is "Goal".
// Example 2:

// Input: command = "G()()()()(al)"
// Output: "Gooooal"
// Example 3:

// Input: command = "(al)G(al)()()G"
// Output: "alGalooG"


#include<stdio.h>
#include<string.h>

char * interpret(char * command){
    static char result[] = ""; 
    int idx = 0;
    for(int i = 0; i< strlen(command); i++)
    {
        if(command[i] == 'G')
        {
            result[idx] = 'G'; 
            idx++;
        }
        if(command[i] == '(' && command[i+1] == ')')
        {
            result[idx] = 'o'; 
            idx++; 
            i++;
        }
        if(command[i] == '\0')
        {
            break;
        }
        if(command[i] == '(' && command[i+1] == 'a')
        {
            result[idx] = 'a'; 
            idx++; 
            result[idx] = 'l'; 
            idx++;
            i = i+3;
            
        }
    }
    return result;
}


int main()
{
    char str[] = "G";
    char *result=  interpret("G");
    printf("result : %s\n", result);

}