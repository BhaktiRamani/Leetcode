#include<iostream>
#include<memory>

using namespace std;

class human{
    public:
    human()
    {
        cout << "Entered human class" << endl;
    }

    void print_class()
    {
        cout << "Inside human class" << endl;
    }

    ~human()
    {
        cout << "Destroyed human class" << endl;
    }
};

// they all are pointing to a same memory - will be deleted after all the pointers goes out of scope
// uses ref count - when ref countgoes to ZERO - it deletes the memory
int main()
{
    //shared ownership
    shared_ptr<human>h1;
    {
        shared_ptr<human> h2 = make_shared<human>();
        {
            shared_ptr<human> h3 = h2;
        }
        weak_ptr<human> h4_w = h2;      //this doesnt have ownership
        //h4_w -> print_class();
        h1 = h2;
        h1 -> print_class();
        
    }
}