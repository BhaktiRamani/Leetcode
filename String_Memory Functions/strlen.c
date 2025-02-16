#include<stdio.h>
#include<string.h>
int my_strlen(char *str);

int main()
{

    char *str = "hello";
    int len = my_strlen(str);
    printf("len %d\n", len);

}

int my_strlen(char *str)
{
    int len = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        len += 1;
    }
    return len;

}