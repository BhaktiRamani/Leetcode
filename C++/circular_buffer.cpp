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
            if(isFull())
            {
                read_index = (read_index + 1) % capacity;
                cout << "Buffer is full" << endl;
            }
       
            buffer[write_index] = data;
            write_index = (write_index + 1) % capacity;
            if(len < capacity) len +=1;
        

            return;
        }

        T dequeue()
        {
            if(!isEmpty())
            {
                T data = buffer[read_index];
                read_index = (read_index + 1) % capacity;
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
                    int index = (read_index + i) % capacity;  // Correct circular indexing
                    cout << buffer[index] << " ";
                }
                cout << endl;
            }
        }


        bool isEmpty()
        {
            return len == 0;
        }

        bool isFull()
        {
            return len == capacity;
        }

};

int main()
{
    circular_buffer<int> cb;

    cb.enqueue(1);
    cb.enqueue(2);
    cb.enqueue(3);
    cb.dequeue();
    cb.print_cb();

    
}

