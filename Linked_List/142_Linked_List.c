// 142. Linked List Cycle II
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
// Example 2:


// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
// Example 3:


// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data; 
    struct node *next;
    int pos; 
}node_t;

typedef struct ll{
    node_t *head;
    int len;
}ll_t;

ll_t* create_LL()
{
    ll_t* ll = (ll_t*)malloc(sizeof(ll_t));
    if(ll != NULL)
    {
        node_t* head = (node_t*)malloc(sizeof(node_t));
        head -> next = NULL;

        ll -> head = head;
        return ll;
    }
    ll -> len = 0;
    return NULL;
}

void add_data(ll_t* ll, int data)
{
    node_t* current = ll -> head; 

    while(current -> next != NULL)
    {
        current = current -> next;
    }
    node_t* tmp = (node_t*)malloc(sizeof(node_t));

    tmp -> next = NULL; 
    tmp -> data = data;
    tmp -> pos = ll -> len;
    ll -> len += 1;
    current -> next = tmp;
 

}

void print_ll(ll_t *ll)
{

    node_t *tmp = ll -> head; 

    while(tmp -> next != NULL)
    {
        tmp = tmp -> next; 
        printf("Data : %d Pos : %d\n", tmp->data, tmp -> pos);
    }
}

bool find_inner_loop_pos(ll_t *ll)
{
    node_t *prev = ll -> head;
    node_t *current = ll -> head -> next; 

    while(current -> next != NULL)
    {
        if(prev -> pos > current -> pos)
        {
            return false;
        }
        current = current -> next; 
        prev = prev -> next;
    }
}
int main()
{
    ll_t* ll = create_LL(); 
    add_data(ll, 1);
    add_data(ll, 2);
    add_data(ll, 3);
    add_data(ll, 4);
    print_ll(ll);


    printf("Length of the list : %d\n", ll -> len);
}