#include<iostream>

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



        void setName(string name)
        {
            this -> name = name;
        }

        string getName() {
            return name;
        }
        
        int getAge() {
            return age;
        }

        // this is used as normal function inside class
        // void output()
        // {
        //     cout << "This is human class" << endl;
        // }

        //virtual keyword uses child's function
        virtual void output(){}
   

};

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

        void output()
        {
            cout << "This is a school class" << endl;
        }
};


int main()
{
    school s("Bhakti", 22, "Atmiya");
    cout << endl;
    s.output();

    //by reference
    human &h = s;
    h.output();

    human hum;
    hum.output();   // will return or print nothing because hum.output points to a virtual function
    // and since hum points to a no child - virtual function has nothing to execute

}

