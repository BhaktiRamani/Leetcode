#include<stdio.h>
#include<string.h>

int my_strcat(char *source, char *destination);

int main()
{
        // Define a temporary variable 
    char example[100] = "Hello ";  // Make sure the array is large enough
    my_strcat("world", example);
    printf("%s\n", example);
}
int my_strcat(char *source, char *destination)
{
    while(*destination != '\0')
    {
        destination++;
    }
    while(*source != '\0')
    {
    
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}