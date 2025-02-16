#include <stdio.h>

#define MAX_SIZE 128
typedef struct stack
{
    char buffer[MAX_SIZE];
    int len;
    int no_of_elements;
}stack_t;

stack_t st = {
    .len = 0,
    .no_of_elements = 0,
};

stack_t st_ptr;
stack_t *st_p = &st_ptr; 

// st_p = {
//     st_p -> len = 0,
//     st_p -> no_of_elements = 0,
// }

void push(stack_t st, char data);
void pop(stack_t st, char *data);
void push_pt(stack_t *ptr, char data);

int main()
{
    st_p -> len = 0;
    st_p -> no_of_elements = 0;

    push_pt(st_p, 'C');
    printf("st_p -> buffer[MAX_SIZE] = %c\n", st_p -> buffer[MAX_SIZE]);


    printf("+++++++++++++++++++++++++++++\n");
    push(st, 'A');
    printf("st.buffer[MAX_SIZE] = %c\n", st.buffer[MAX_SIZE]);
    printf("st.len = %d\n", st.len);
    printf("st.no_of_elements = %d\n", st.no_of_elements);
}


void push_pt(stack_t *ptr, char data)
{
    printf("data %c\n", data);
    if(ptr -> len == 0)
    {
        ptr -> buffer[MAX_SIZE] = data;
    }
    else
    {
        ptr -> buffer[MAX_SIZE - (ptr -> len) - 1] = data;
    }
    printf("ptr -> buffer[MAX_SIZE] = %c\n", ptr -> buffer[MAX_SIZE]);
    ptr -> len++;
    ptr -> no_of_elements++;
    printf("ptr -> buffer[MAX_SIZE] = %c\n", ptr -> buffer[MAX_SIZE]);
}

void push(stack_t st, char data)
{
    if(st.len == 0)
    {
        st.buffer[MAX_SIZE] = data;
        printf("st.buffer[MAX_SIZE] = %c\n", st.buffer[MAX_SIZE]);
    }
    else
    {
        st.buffer[MAX_SIZE - st.len - 1] = data;
    }

    printf("st.buffer[MAX_SIZE] = %c\n", st.buffer[MAX_SIZE]);
    st.no_of_elements = st.no_of_elements + 1;
    st.len = st.len + 1;
    printf("st.buffer[MAX_SIZE] = %c\n", st.buffer[MAX_SIZE]);
}

void pop(stack_t st, char *data)
{
    data = &(st.buffer[MAX_SIZE - st.len]);
    st.len--;
    st.no_of_elements--;
}