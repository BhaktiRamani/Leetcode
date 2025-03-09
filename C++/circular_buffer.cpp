#include<iostream>
#include<stdbool.h>

using namespace std;

#define MAX_LEN 3

template <typename T>
class circular_buffer{
    private:
        T buffer[MAX_LEN];
        int read_index, len, write_index;
        int capacity = MAX_LEN;

    public:
        circular_buffer()
        {
            read_index = 0;
            len = 0;
            write_index = 0;
        }
        void enqueue(T data)
        {
            if(!isFull())
            {
                buffer[write_index] = data;
                write_index = (write_index + 1) & capacity;
                len += 1;
                return;
            }
            cout << "Buffer is full" << endl;
            return;
        }

        T dequeue()
        {
            if(!isEmpty())
            {
                T data = buffer[read_index];
                read_index = (read_index + 1) & capacity;
                len -= 1;
                return data;
            }

            return T{};
        }

        void print_cb()
        {
            if(!isEmpty())
            {
                for(int i = 0; i < len; i++)
                {
                    cout << buffer[len] << " " << endl;
                }
            }
        }


        bool isEmpty()
        {
            return len == 0;
        }

        bool isFull()
        {
            cout << len << capacity << endl;
            cout << "result " << (len == capacity) << endl;
            return len == capacity;
        }

};

int main()
{
    circular_buffer<int> cb;

    cb.enqueue(1);
    cb.enqueue(2);
    cb.enqueue(3);
    cb.print_cb();

    
}

