#include <iostream>

using namespace std;

template< typename T>
struct node{
    T data;
    node* next;
};

template <typename T>
class LL{
    private:
        node<T> *head;

    public:
        LL(){
            head = nullptr;
        }

        node<T>* create_Node(T data)
        {
            node<T>* new_node = new node<T>;
            new_node -> data    = data;
            new_node -> next = nullptr;
            return new_node;
        }

        void add_elements(T data)
        {
            node<T>* new_node = create_Node(data);
            if(head == nullptr)
            {
                head = new_node;
            }
            else{
                node<T>* temp = head;
                while(temp -> next != nullptr)
                {
                    temp = temp -> next;
                }
                temp -> next = new_node;

            }
        }

        void print_LL()
        {
            node<T>* temp = head;
            while(temp != nullptr)
            {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }

        // use destructor to free the allocated memory
        

};

int main()
{
    LL<int> ll_init;
    ll_init.add_elements(1);
    ll_init.add_elements(2);
    ll_init.add_elements(3);
    ll_init.add_elements(4);

    ll_init.print_LL();

    LL<string>string_ll;
    string_ll.add_elements("Hello");
    string_ll.add_elements("World");
    string_ll.print_LL();

  

}