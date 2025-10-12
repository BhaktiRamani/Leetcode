// 83. Remove Duplicates from Sorted List
// Easy
// Topics
// premium lock icon
// Companies
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]


#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data; 
    struct node* next;
}node_t;

typedef struct{
    node_t *head; 
    int len;
}ll_t;

ll_t *create_LL()
{
    ll_t* ll = (ll_t*)malloc(sizeof(ll_t*)); 
    ll -> head = (node_t*)malloc(sizeof(node_t*));
    ll -> head -> next = NULL; 
    ll -> len = 1;

    if(ll -> head != NULL)
    {
        return ll;
    }
    return NULL;
}

void add_data(ll_t *ll, int data)
{
    node_t *tmp = ll -> head; 
    node_t *current = ll -> head;
    while(tmp -> next != NULL)
    {
        tmp = current -> next; 
        current = current -> next; 
    }
    node_t *new_node = (node_t*)malloc(sizeof(node_t*)); 
    new_node -> next = NULL; 
    new_node -> data = data; 

    tmp -> next = new_node;
}

void print_ll(ll_t *ll)
{

    node_t *tmp = ll -> head; 

    while(tmp -> next != NULL)
    {
        tmp = tmp -> next; 
        printf("Data : %d\n", tmp->data);
    }
}


node_t* deleteDuplicates(ll_t* ll) {
    node_t *first = ll -> head -> next;
    node_t *sec = ll -> head -> next -> next; 
    printf("first : %d sec : %d\n", first -> data, sec -> data);
    while(first -> next != NULL)
    {
        printf("first : %d sec : %d\n", first -> data, sec -> data);
        while(first -> data == sec -> data)
        {
            printf("first : %d sec : %d\n", first -> data, sec -> data);
            // first = sec -> next;
            sec = sec -> next;
        }
        first -> next = sec;
        first = first -> next; 
        sec = first -> next;
        printf("\n");
    }
    return ll -> head;
    
}
int main()
{
    ll_t *head = create_LL();

    add_data(head, 1);
    add_data(head, 1);
    add_data(head, 2);
    add_data(head, 2);
    add_data(head, 3);

    print_ll(head);
    deleteDuplicates(head);
    print_ll(head);
}