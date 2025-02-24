#include<stdio.h>
#include<string.h>

char* my_strncpy(char *destination, const char* source, unsigned int n);

int main()
{
    char str1[] = "hello world";
    char str2[50] = "whats up";
    my_strncpy(str2, str1, 4);
    printf("str1 %s\nstr %s\n", str1, str2);
    
    
}

char* my_strncpy(char *destination, const char* source, unsigned int n )
{
    char *original_destination = destination;
    
    int i = 0;
    for(i = 0; i<n && *source != '\0'; i++)
    {
        *destination = *source;
        destination++;
        source++;
    }
    return original_destination;

}