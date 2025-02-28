#include <iostream>

using namespace std;

typedef struct node{
    int data;
    node* next;
}node_t;

node_t* create_LL()
{
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head -> next = NULL;
    head -> data = 0xFFFF;
    return head;
}

int add_elements(int data, node_t *head)
{
    if(head!= NULL && head -> data == 0xFFFF)
    {
        cout <<"Loop 1" << endl;
        head -> data = data;
    }
    else if(head -> data != 0xFFFF && head -> next == NULL)
    {
        node_t *temp = (node_t*)malloc(sizeof(node_t));
        temp -> data = data;
        temp -> next = NULL;
        head -> next = temp;
        cout <<"Loop 2" << endl;
    }
    else
    {
        node_t *temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        node_t *prev = (node_t*)malloc(sizeof(node_t));
        prev -> next = NULL;
        prev -> data = data;
        temp -> next = prev;
        cout <<"Loop 3" << endl;

    }
    return 0;

}

void print_LL(node_t *head)
{
    node_t *temp = head;
    while(temp != NULL)
    {
        //cout <<"Loop 4" << endl;
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    node_t *head = create_LL();
    add_elements(1, head);
    add_elements(2, head);
    add_elements(3, head);
    

    print_LL(head);
}

