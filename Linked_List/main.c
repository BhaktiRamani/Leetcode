#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

int add_elements(node_t *head, int data);
node_t* create_LL();
void print_LL(node_t* head);
void add_any_elements(node_t *head, void* data_v, int data_len);

int main()
{
    node_t* head = create_LL();
    // add_elements(head, 1);
    // add_elements(head, 2);
    // add_elements(head, 3);

    int array[5] = {1, 2, 3, 4, 5};

    add_any_elements(head, array, 5);

    char *str = "Hello";

    add_any_elements(head, str, 5);

    printf("\n");
    print_LL(head);
    printf("\n");
}

node_t* create_LL()
{
    node_t *head = NULL;
    head = (node_t*)malloc(sizeof(node_t));

        
    if(head == NULL) return 0;

    head -> data = 0;
    head -> next = NULL;

    return head;
}

void add_any_elements(node_t *head, void* data_v, int data_len)
{
    node_t *prev;

    char* data = (char *)data_v;
    
    for(int i = 0; i < data_len; i++)
    {
        if(head -> data == 0 && head -> next == NULL)
        {
            head -> data = *data;
            printf("head -> data %c\n", head -> data);
            printf("data %c\n", *data);
            *(data++);
           
        }
        else if(head -> data != 0 && head -> next == NULL)
        {
            
            node_t *temp = (node_t*)malloc(sizeof(node_t));
            printf("data %c\n", *data);
            temp -> data = *data;
            temp -> next == NULL;
            head -> next = temp;
            prev = head -> next;
            printf("head -> next -> data %c\n", head -> next -> data);
            *(data++);
        }
        else
        {
            node_t *temp = (node_t*)malloc(sizeof(node_t));
            printf("data %c\n", *data);
            temp -> data = *data;
            temp -> next == NULL;
            prev -> next = temp;
            prev = prev -> next;
            *(data++);
        }
    }



}

int add_elements(node_t *head, int data)
{
    node_t *current;
    if(head -> data == 0 && head -> next == NULL)
    {
        
        head -> data = data;

        
    }
    else if(head -> data != 0 && head -> next == NULL)
    {
     
        node_t *temp = (node_t *)malloc(sizeof(node_t));
        temp -> data = data;
        temp -> next = NULL;
        head -> next = temp;
        current = head -> next;
    
    }
    else
    {

        node_t *temp = (node_t *)malloc(sizeof(node_t));
        temp -> data = data;
        temp -> next = NULL;
        current -> next = temp;
        current = current -> next;
    }
}

void print_LL(node_t *head)
{
    node_t *temp = head;
    while(temp != NULL)
    {
        printf("%c -> ", temp -> data);
        temp = temp -> next;
    }
}