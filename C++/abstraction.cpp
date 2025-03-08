#include<iostream>

using namespace std;

/*
    base class(animal) has at least one virtual function.so user cant use that class
    it has to point to a child class which uses that virtual function

    const override function is used to declare virtual function in child class
*/

class animal{
    public:
        //IMP
        virtual void sound() const = 0;
};

class dog : public animal{
    private:
        string name = "Dog";
    public:
        //IMP
        void sound() const override
        {
            cout << name << ": Bark Bark!" << endl;
        }
};


int main()
{   
    cout << endl;
    dog d;
    animal &a = d;
    a.sound();
}