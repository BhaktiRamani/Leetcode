
// Code
// Testcase
// Test Result
// Test Result
// 141. Linked List Cycle
// Easy
// Topics
// premium lock icon
// Companies
// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.


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

bool find_inner_loop(ll_t *ll)
{
    node_t* fast_ptr = ll -> head; 
    node_t* slow_ptr = ll -> head;

    int len = ll -> len*3; 
    while(fast_ptr != NULL && fast_ptr -> next != NULL)
        {
            slow_ptr = slow_ptr -> next; 
            fast_ptr = fast_ptr -> next -> next; 
            if(slow_ptr == fast_ptr)
            {
                return true;
            }
        }
    return false;
}
int main()
{
    ll_t* ll = create_LL(); 
    add_data(ll, 1);
    add_data(ll, 2);
    add_data(ll, 5);
    print_ll(ll);

    int result = find_inner_loop(ll); 
    printf("Inner loop result : %d\n", result);
    return 0;
}