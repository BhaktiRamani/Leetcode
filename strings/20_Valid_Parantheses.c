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

typedef struct{
    char buffer[8];
    int len;
}stack;

void push2(stack *arr, char element)
{
    arr -> buffer[arr -> len] = element;
    arr -> len += 1;
}

char pop2(stack *arr)
{
    arr -> len -= 1;
    char element = arr -> buffer[arr -> len];
    return element;
}

void print_stack(stack *arr)
{
   
    for(int i = 0; i < arr -> len; i++)
    {
        printf("%c , ", arr -> buffer[i]);
    }
    printf("\n");
}

bool hash(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    if(a == '{' && b == '}')
        return true;
    if(a == '[' && b == ']')
        return true;
    return false;
}
bool isValid3(char* s) {

    int length = strlen(s);

    if(length%2 != 0)
    {
        return false;
    }
    stack left_arr;
    stack right_arr;

    left_arr.len = 0;
    right_arr.len = 0;

    for(int i = 0; i < length/2; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            printf("Push %c left arr with index %d\n", s[i], left_arr.len);
            push2(&left_arr, s[i]);
        }
        else
        {
            printf("Nothing\n");
        }
    }

    
    for(int i = length - 1; i >= length/2; i--)
    {
       
        if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            printf("Push %c right arr with index %d\n", s[i], right_arr.len);
            push2(&right_arr, s[i]);
        }
      
    }
    printf("\n");
    printf("Left arr : ");
    print_stack(&left_arr);
    printf("Right arr : ");
    print_stack(&right_arr);
    bool result; 
    printf("Left arr.len : %d\n", left_arr.len);
    printf("Right arr.len : %d\n", right_arr.len);
    printf("\n");
    for(int i = 0; i < length/2; i++)
    {
        char a = pop2(&left_arr);
        char b = pop2(&right_arr);

        printf("a : %c b : %c\n", a, b);
        result = hash(a,b);
        if(result == false)
        {
            return false; 
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

    // char str[6] = {'(', ')', '{', '}', '[', ']'};
    // bool status = isValid(str);
    
    // printf("str %s\n", BOOL(status));

    // char *str = "({})";
    // bool result = isValid2(str);
    // printf("Result : %d\n", result);


    int result = isValid3("()[]{}");
    printf("Result is : %d\n", result);

    return 0;
}