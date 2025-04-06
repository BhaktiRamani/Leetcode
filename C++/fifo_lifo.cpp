#include<iostream>
#define MAX_LEN 128
using namespace std;

template <typename T>
class lifo_fifo{
    private:
        T buffer[MAX_LEN];
        int current_len = 0;
        int pull_index = 0;

    public:

        void push(T data)
        {
            if(!isFull())
            {
                buffer[current_len] = data;
                current_len+=1;
                return;
            }
            cout << "Buffer is full" << endl;

        }

        T pop()
        {
            if(!isEmpty())
            {
                current_len -= 1;
                T popped_data = buffer[current_len];
                //cout << "current len after pop : " << current_len << endl;
                return popped_data;
            }
            cout << "Buffer is empty" << endl;

            return T{};

        }

        T pull()
        {
            if(!isEmpty())
            {
                T pulled_data = buffer[pull_index];
                pull_index +=1;
                current_len -= 1;
                return pulled_data;
            }
            cout << "Buffer is Empty" << endl;
            return T{};
        }

        void peek()
        {
            cout << "Next element to be pop : " << buffer[current_len - 1] << endl;
        }

        bool isEmpty()
        {
            return current_len == 0;
        }

        bool isFull()
        {
            return (current_len) == MAX_LEN;
        }

        int size()
        {
            return current_len;
        }

        void print_st()
        {
            if(!isEmpty())
            {
                for(int i = (current_len - 1); i >= 0; i--)
                {
                    cout << buffer[i] << " " << endl;
                    
                }
                cout << "Current Len : " << current_len << endl;
                return;
            }
            return;
            
            cout << endl;
        }

        void print_fifo()
        {
            if(!isEmpty())
            {
                // Issuew
                for(int i = pull_index; i <= current_len ; i++)
                {
                    cout << buffer[i] << " ";
                }
                cout << "Current len : " << current_len << endl;
                return;
            }

            cout << "Buffer is empty" << endl;
            return;

        }
};

int main()
{
    // cout << endl;
    // lifo_fifo<char> stack;
    // stack.push('A');
    // stack.push('B');
    // stack.push('C');
    // stack.push('D');

    // stack.print_st();

    // stack.pop();
    // // stack.push('C');
    // // stack.peek();
    // stack.print_st();

    cout << endl;
    lifo_fifo<char> fifo;
    fifo.push('A');
    fifo.push('B');
    fifo.push('C');
    fifo.push('D');
    fifo.print_fifo();

    fifo.pull();
    fifo.print_fifo();

}