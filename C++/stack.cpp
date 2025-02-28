#include<iostream>

using namespace std;

#define MAX_LEN 128

template <typename T>
class stack{
    private:
        T array[128];
        int current_len;

    public:
        stack()
        {
            this -> current_len = MAX_LEN;
        }
        
        int push(T data)
        {
            if(current_len == 0)
            {
                cout << "Stack is full" << endl;
                return -1;
            }    
            current_len --;
            array[current_len] = data;
            cout << "Pushing " << array[current_len] << " In Stack "<< "Current len " << current_len << endl;
            cout << endl;
        }

        T pop()
        {
            if(current_len == MAX_LEN - 1)
            {
                cout << "Stack is empty" << endl;
                // /return -1;
            }
            T element = array[current_len];
            cout << "Popping out " << element << " Current len " << current_len <<  endl;
            current_len++;
            return element;
         
        }

        void info()
        {
            cout << "Currently " << (MAX_LEN - current_len) << " Elements in Stack" << endl;
            int temp = MAX_LEN - current_len;
            for(int i = current_len; i < MAX_LEN; i++)
            {
                cout << array[i] << " " << endl;
            }
          
            cout << endl;

        }

        void peek()
        {
            if (current_len == MAX_LEN) {
                cout << "Stack is empty, no elements to peek" << endl;
            } else {
                cout << "Next element to be popped is: " << array[current_len] << endl;
            }
            
        }

};


int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.info();
    st.pop();
    st.info();
    st.peek();

    stack<string> str;
    str.push("bottom");
    str.push("there");
    str.push("Random");
    str.push("Top");
    str.info();
    str.peek();
}