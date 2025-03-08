#include<iostream>

//encapsulation is basically hiding the private data and use of gettars and adders 
// it is to give controlled access, and data hiding from user
// ex : Bank account class can take parameters as bank account number , interest, year, amount and
// then process it to calculate interest, deposit or other stuff. But there is no need to expose the private variables
// like account number to user so we can put it in private


using namespace std;

class human{
    private:
        string name;
        int age;

    public:
        human(string name)
        {
            this -> name = name;
           
        }
        human(string name, int age)
        {
            this -> name = name;
            this -> age = age;
        }
        human()
        {
            
        }

        void getName()
        {
            cout << this -> name << endl;
        }

        void setName(string name)
        {
            this -> name = name;
        }

};

int main()
{
    human bhakti("Bhakti");
    bhakti.getName();
   
}