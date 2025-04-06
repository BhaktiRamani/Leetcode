// input : this is a string
// output : string a is this

#include<stdio.h>

void reverse(char *str)
{
    int strlen = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        strlen+=1;
    }

    int right_index = strlen;
    int right_str_size = 0;
    while(str[right_index] != ' ')
    {
        right_index-=1;
        right_str_size+=1;
    }


    int left_str_size = 0;
    while(str[left_str_size] != ' ')
    {
        left_str_size+= 1;
    }
    int left_index = 0;

    int max_size = 0;
    max_size = right_str_size > left_str_size ?  right_str_size :  left_str_size;

    right_index +=1;
    printf("Left index : %d Right index : %d %c\n", left_index, right_index, str[right_index]);
    for(int i = left_index; i< max_size; i++)
    {
        printf("Left : %c Right : %c\n", str[i], str[right_index]);
        char temp = str[i];
        str[i] = str[right_index];
        str[right_index] = temp;
        right_index+=1;
    }

    printf("Ouput str is : %s\n", str);


}

int main()
{
    reverse("this is a string");
}