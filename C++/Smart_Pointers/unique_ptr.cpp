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

int main()
{
    
    {
        unique_ptr<human> h = make_unique<human>();
        h -> print_class();

    }
}