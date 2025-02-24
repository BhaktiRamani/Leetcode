#include<stdio.h>
#include<string.h>

int my_strrchr(const char* str, int ch);

int main()
{
    char *str = "Hello World";
    printf("result d\n");
    my_strrchr(str, 'o');
}
int my_strrchr(const char* str, int ch)
{
    int res = 0;
    for(int i = 0; *str != '\0'; i++)
    {
        if(*str == ch)
        {
            res = i;
            break;
            
        }
        str++;
    }
    printf("result %d\n", res);
}