#include<iostream>
#define MAX_LEN 128

using namespace std;

template<typename T>
class fifo{
    private:
        int read_index;
        int write_index;
        T array[MAX_LEN];
        int current_len;

    public:
        fifo()
        {
            this -> read_index = 0;
            this -> write_index = 0;
            this -> current_len = 0;
        }

        void push(T data)
        {
            if(write_index == MAX_LEN)
            {
                cout << "Fifo is full" << endl;
                return;
            }
            array[write_index] = data;
            write_index = (write_index + 1) % MAX_LEN;
            current_len++;
        }

        T pop()
        {
         
            if(current_len == 0)
            {
                cout << "FIFO is empty" << endl;
                return -1;
            }
            T element = array[read_index];
            read_index = (read_index + 1) % MAX_LEN;
            current_len--;
            cout << "Popping out " << element << endl;
            return element;
        }

        void info()
        {
            cout << "Currently " << current_len  << " Elements in a FIFO" << endl;
            for(int i = 0; i < current_len; i++)
            {
                cout << array[(read_index + i) % MAX_LEN] << " " << endl;
            } 
        }
    

};

int main()
{
    fifo<int> fifo_i;
    fifo_i.push(1);
    fifo_i.push(2);
    fifo_i.info();
    fifo_i.pop();
    fifo_i.info();

}