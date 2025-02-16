#include<stdio.h>
#include<string.h>


char* my_strcpy(char *destination, const char* source );

int main()
{
    char str1[] = "hello world";
    char str2[50] = "yoo";
    my_strcpy(str2, str1);
    printf("str1 %s\nstr %s\n", str1, str2);
}

char* my_strcpy(char *destination, const char* source )
{
    char *original_destination = destination;
    for(int i = 0; source[i] != '\0'; i++)
    {
        *destination = *source;
        destination++;
        source++;
        
    }
    *destination = '\0';
    return original_destination;

}