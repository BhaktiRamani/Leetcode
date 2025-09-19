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

bool isValid2(char* s) {
    
    // s = "()"
  
    char *first = s;
    // s++;
    char *next = s++;
    // printf("%c %c\n", *first, *s);

    char buffer[8];
    int buffer_len = 0;
    while(*s!='\0')
    {
        if(*s == '(' || *s == '{' || *s == '[')
        {
            printf("Here %c\n", *s);
            buffer[buffer_len] = *s;
            buffer_len++;
        }
        s++;

    }
    s--;
    buffer_len--;
    // printf("%c \n", *s);

    for(int i = 0; i<=buffer_len; i++)
    {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    while(buffer_len>=0)
    {
        printf("buffer[buffer_len] : %c *s : %c, buffer_len : %d\n", buffer[buffer_len], *s, buffer_len);
        if(buffer[buffer_len] == '(' && *s == ')' || buffer[buffer_len] == '{' && *s == '}' || buffer[buffer_len] == '[' && *s == ']')
        {
            printf("Same\n");
        }
        else
        {
            printf("False");
            return false;
        }
        buffer_len--;
        s--;
        
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

    // char str[6] = {'(', ')', '{', '}', '[', ']'};
    // bool status = isValid(str);
    
    // printf("str %s\n", BOOL(status));

    char *str = "({})";
    bool result = isValid2(str);
    printf("Result : %d\n", result);
    return 0;
}