#include<stdio.h>
#include<string.h>

int my_strncmp(char *str1, char *str2, unsigned int n);

int main()
{
    // defining two similar strings
    char* str1 = "GeeksforGeeks";
    char* str2 = "Geeks For Geeks";

    // comparing first 5 characters of each
    int value = strncmp(str1, str2, 5);
    printf("result %d\n", value);
}

int my_strncmp(char *str1, char *str2, unsigned int n)
{
    int i = 0;
    while(*str1 != '\0' && *str2 != '\0' && i < n)
    {
        if(*str1 != *str2)
        {
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
        i++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
    
}