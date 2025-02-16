#include <stdio.h>
#include <string.h>
int normal_method_palindrome(char *str);
int reversing_method_palindrome(char *str);

int main()
{
    char str[6] = "Bhakti";
    if(normal_method_palindrome(str) == 1) printf("String %s is Palindrome\n", str);
    else printf("String is not palindrome\n");

    if(reversing_method_palindrome(str) == 1) printf("String %s is Palindrome\n", str);
    else printf("String is not palindrome\n");
    
}


int reversing_method_palindrome(char *str)
{
    int str_len = strlen(str);

    char original_str[str_len] = str;
    //original_str[str_len] = str;
    if(str_len%2 != 0 || str_len == 0)
    {
        
        return 0;
    }

    char temp;
    for(int i = 0, j = (str_len - 1); i < (str_len / 2); i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;    
    }
    printf("Reversed String %s \n", str);
    printf("original_str  %s \n", original_str);
    if(strcmp(original_str, str) == 0) return 1;
}
int normal_method_palindrome(char *str)
{
    int str_len = strlen(str);

    if(str_len%2 != 0 || str_len == 0)
    {
        
        return 0;
    }

    int same = 0;
    for(int i = 0, j = (str_len - 1) ; i < (str_len/2); i++, j-- )
    {
        if(str[i] == str[j])
        {
            same += 1;
        }
    }
  
    if(same == str_len/2)
    {
        return 1;
    }
    return -1;
}