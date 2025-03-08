#include<iostream>

using namespace std;

class animal{
    public:
        virtual void sound(){}
};

class dog : public animal{
    private:
        string name = "Dog";
    public:
        void sound()
        {
            cout << name << ": Bark Bark!" << endl;
        }
};

class duck : public animal{
    private:
        string name = "duck";
    public:
        void sound()
        {
            cout << name << ": Quack Quack!" << endl;
        }
};


int main()
{
   
    dog puppy;
    duck batak;
    animal* arr_of_animals[2] = {&puppy, &batak};
    animal* a;

    for(int i = 0; i < 2; i++)
    {
        a = arr_of_animals[i];
        a -> sound();
        //arr_of_animals[i] -> sound();
    }


}
