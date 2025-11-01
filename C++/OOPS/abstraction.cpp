#include<iostream>

using namespace std;

/*
    base class(animal) has at least one virtual function.so user cant use that class
    it has to point to a child class which uses that virtual function

    const override function is used to declare virtual function in child class

    basically - we do not want to show main class(animal) so we are putting virtual function it it

    that way - we will not be able to define main class and it needs a reference(child) class to point to.
*/

class animal{
    public:
        //IMP
        virtual void sound() const = 0;

        void speak(){
            sound();
        }
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

class cat : public animal{
    private:
        string name = "Cat : ";
    public:
        //IMP
        void sound() const override
        {
            cout << name << "Meow Meow!" << endl;
        }
};



int main()
{   
    cout << endl;
   //animal a;  // will throw an error
    dog d;
    animal &a = d;
    a.speak();


    cat c; 
    animal &b = c; 
    b.speak();

}