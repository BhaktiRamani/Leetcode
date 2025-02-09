/*Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm". */

#include <stdio.h>
#include <string.h>

int main()
{
    char *array[5] = {"Hello", "World"};
    char *row1 = "qwertyuiop";
    char *row2 = "asdfghjkl";
    char *row3 = "zxcvbnm";

    printf("%s     and %c\n", array[0], *(array[0] + 1));
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<10; j++)
        {
            *(array[i] + 0) = 1; 
        }
    }

 
    
}