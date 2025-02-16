#include<stdio.h>
#include<string.h>

int my_strcmp(char *str1, char *str2);

int main()
{
    char first_str[] = "bfb";
    char second_str[] = "bfb";
    int result = strcmp(first_str, second_str);
    printf("result %d\n", result);
}

int my_strcmp(char *str1, char *str2)
{
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 != *str2)
        {
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }
    return 0; //(unsigned char)*str1 - (unsigned char)*str2;
    
}