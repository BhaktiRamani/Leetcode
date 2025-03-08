#include<iostream>

/* Inheritance is using differe/parent class's attributes into child class
SYNTAX is imp
*/
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
        string getName() {
            return name;
        }
        
        int getAge() {
            return age;
        }
};

//IMP
class school : public human{
    private:
        string school_name;
    public:
        school(string school_name)
        {
            this -> school_name = school_name;
        }
        //IMP
        school(string name, int age, string school_name) : human(name, age) // Call parameterized constructor of human
        {
            this -> school_name = school_name;
        }

        void setSchoolName(string school_name)
        {
            this -> school_name = school_name;
        }

        void getSchoolName()
        {
            cout << "School Name" << this -> school_name << endl;
            cout << "Person Name: " << getName() << endl; // Access base class data
            cout << "Person Age: " << getAge() << endl;
        }
};

int main()
{
   
    school Atmiya("Bhakti", 22, "Atmiya");
    Atmiya.getSchoolName();

    
}