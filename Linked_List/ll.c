#include "ll.h"

typedef struct _node{
    int data;
    struct _node* next;
}_node_t;

typedef struct{
    int len;
    int max_len;
    _node_t *head;
}_ll_t;

ll_t *create_head(int max_len, int head_data)
{
    _ll_t* ll = (_ll_t*)malloc(sizeof(*ll));
    ll -> len = 1;
    ll -> max_len = max_len;

    ll -> head = (_node_t*)malloc(sizeof(_node_t));
    ll -> head -> data = head_data;

    ll -> head -> next = NULL;
     
    return (ll_t *)ll;
}

int append(ll_t* ll, int data)
{
    
    _ll_t *_ll = (_ll_t*)ll;
    _node_t *temp = _ll -> head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next= (_node_t*)malloc(sizeof(_node_t));
    // add malloc check


    temp -> next -> data = data;
    //printf("Adding element %d saved %d\n", data, head -> base -> next -> data);
    temp ->  next -> next = NULL;

    
}

void print_LL(ll_t *ll)
{
    _ll_t *_ll = (_ll_t*)ll;
    _node_t* temp = _ll -> head;
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");

}

void push(ll_t *ll, int data){
    _ll_t *_ll = (_ll_t*)ll;
    _node_t *temp = (_node_t*)malloc(sizeof(*temp));
    temp -> data = data;

    _node_t *head_ptr = _ll -> head;
    temp -> next = head_ptr;
    // printf("head_ptr %d\n", (long int)(*head_ptr));
    _ll -> head = temp;

}

int pop(ll_t *ll)
{
    _ll_t *_ll = (_ll_t*)ll;
    _node_t *temp = _ll -> head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    _node_t *popped_node = temp -> next;
    int data = temp->data;
    temp -> next = NULL;
    free(popped_node);
    return data;
}

int pull(ll_t *ll){
    _ll_t *_ll = (_ll_t*)ll;
    int pulled_data = _ll -> head -> data;

    _node_t* pulled_node = _ll-> head;
    _node_t* temp = _ll -> head -> next;
    _ll -> head = temp;
    free(pulled_node);

    return pulled_data;


}

void reverse_ll(ll_t *ll)
{
    // node_t *prev = (node_t*)malloc(sizeof(node_t));

    // node_t* next_node;
    // node_t* current_node;

    // next_node = ll -> head -> next;

    // ll -> head -> next = prev;



}
