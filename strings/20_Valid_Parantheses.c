// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define BOOL(x) ((x==0) ? "false" : "true")

typedef struct stack{
    char buffer[8];
    int len;
}stack_t;

stack_t st = {
    .len = 7,
};

void push(char data)
{
    st.buffer[st.len] = data;
    printf("pushed %c \n", st.buffer[st.len]);
    st.len--;

}

char pop()
{
    st.len++;
    char data = st.buffer[st.len];
    printf("Popping out %c with len %d\n", st.buffer[st.len], st.len);
    return data;
}

bool isValid(char* s) {

    for(int i = 0; i< strlen(s); i++)
    {
        push(s[i]);
    }
    printf("\n");
    for(int j = 7; j > 1; j--)
    {
        printf("%c ", st.buffer[j]);
    }
    printf("\n");
    for(int i = 0; i<strlen(s); i++)
    {   
        char br = s[i];

        for(int j = 7; j > 1; j--)
        {
            printf("%c ", st.buffer[j]);
        }
        printf("\n");
        if(br == '(' || br == '[' || br == '{')
        {
            char popped = pop();
            if((int)(popped + br) == 82 || (int)(popped + br) == 248 || (int)(popped + br) == 184 )
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    
    char c = '{';
    char d = '}';
    int a = c;
    // push(c);
    // printf("char %c len %d \n", st.buffer[st.len + 1], st.len);
    // push(d);
    // printf("char %c len %d \n", st.buffer[st.len + 1], st.len);

    // char popped = pop();
    // printf("len %d popped %c\n", st.len, popped);
    // printf("%d  %d\n", a, (int)d);

    char str[6] = {'(', ')', '{', '}', '[', ']'};
    bool status = isValid(str);
    
    printf("str %s\n", BOOL(status));
}