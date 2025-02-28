#include<iostream>
#include<array>
#include<vector>

using namespace std;

template <typename T, typename U>  // or template <class T>
auto result(T parameter, U val) {
    // function body
    return parameter + val;
}

void string_recap()
{
    cout << endl;
    string hello = "Hello";
    string world = "World";
    // append
    string all = hello + " " + world;
    all += "!";
    all.append("+");
    cout << all << endl;

    //length check
    int len = all.length();
    cout << "Str len : " << len << endl;

    //accessing characters 
    char c = all[3];
    char last = all.back();
    cout << c << endl;
    cout << last << endl;

    // can access-create substring 
    string substring = all.substr(4, 4);
    cout << substring << endl;

    //finding position
    int position = all.find("!+");
    cout << position << endl;

    // replacing the string
    all.replace(11, 2, "--");
    cout << all << endl;

    //comparision
    bool isEqual = (all == "Hello World--");
    cout << isEqual << endl;

    //user input for string
    string user_input;
    cout << "Enter a str : ";
    getline(cin, user_input);
    cout << user_input << endl;
}

void array_recap()
{
    // array initialization
    array<int, 5>arr = {1 ,2 , 3, 4 ,5};
    cout << arr[0] << endl;

    //array size
    int len = arr.size();
    cout << len << endl;

    //other helpful things
    int front = arr.front();
    int back = arr.back();
    cout << "Front " << front << " Back " << back << endl;

        // 3 rows, 4 columns
        std::array<std::array<int, 4>, 3> matrix = {{
            {{1, 2, 3, 4}},
            {{5, 6, 7, 8}},
            {{9, 10, 11, 12}}
        }};
    
        // Accessing elements
        int value = matrix[1][2]; // Row 1, Column 2
    
        // Using at() for bounds checking
        int safeValue = matrix.at(1).at(2);
    
        // Size information
        size_t rows = matrix.size();
        size_t cols = matrix[0].size();
    
        cout <<matrix[2][3] << endl;
}

void vector_recap()
{
    // vector gets stored dynamically in heap. so size is undefined
    vector<int> vect = {1 , 2, 3};
    cout << vect[0] << endl;

    //other helpful stuff
    vect.push_back(4);  //push at the end
    vect.pop_back();    //pop from the end
    vect.insert(vect.begin() + 2, 5);  // insert at index 3 data '5'
    vect.erase(vect.begin());
    cout << vect[0] << endl;
    cout << vect[1] << endl;
    cout << vect[2] << endl;
    cout << vect[3] << endl;

    // size
    int size = vect.size();
    cout << size << endl;
}

class Human
{
    // can be accessed from anywhere
    public:
        int age;
        string name;

        // member function
        void info()
        {
            cout << "This is Human class" << endl;
        }

        // setters - private variable can be set but here there should be some logic to prevent wrong usage
    
        void set_work_ex(int x)
        {
            work_ex = x;
        }

        // getters
        int get_work_ex()
        {
            return work_ex;
        }
    private:
        int work_ex;
};

void normal_class()
{
    Human bhakti;
    bhakti.name = "Bhakti";
    bhakti.age = 22;
    bhakti.info();
    bhakti.set_work_ex(2);
    cout << bhakti.get_work_ex() << endl;
}


class cars{
    public:
        string name;
        int year;
        string car2;
        int *data;
        static string member;
        
    static void func()
    {
        cout << "This is static func" << endl;
    }

    // Overloaded constructer - multiple consructor can be available for same class
    // constructor - takes argument in class
    cars(string name, int year){
        this -> name = name;
        this -> year; 
        // allocating memory in heap using constructor
        data = new int(0);
        // we can also assign name and year parameters as just name = (input x ) and this can also be used
    }

    // multiple constructors can be make
    cars(string name, int year, string car2)
    {
        this -> name = name;
        this -> year;
        this -> car2 = car2;
    }

    // c any car
    cars()
    {

    }

    // Destructor -- Automatically called when execution of class is finished - to help clear the dynamic memory 
    // close open files etc
    ~cars()
    {
        delete data;
    }
};

void constructor_class()
{

    cars mycar("ZOOX", 2024);
    cout << mycar.name << endl;

    cars bothcar("ZOOX", 2024, "Swift");
    cout << bothcar.car2 << endl;

    cars nocar;
    cout << nocar.name << endl;
}

class mycar1 : public cars{
    public:
        void info2()
        {
            cout << "this is mycar1 class" << endl;
        }
};

string cars::member = "STATIC";

int main()
{
    cout << "Hello World !" << endl;
    string str = "String";
    cout << str << endl;
    int int_v = 3040;
    cout << "Int variable " << int_v << endl;

    cout << endl;

    cars mycar("ZOOX", 2024);
    cout << mycar.name << endl;

    // so centro will have attributes of mycar1 class and cars class both  
    mycar1 centro;
    centro.info2();


    // static member of a class
    cout << cars :: member << endl;
    //static function
    cars ::func();
}


void general_stuff()
{

    // Fill function - same as memset
    string food[5];
    string foods;
    fill(food, food+5, "Cake");
    
    for(int i = 0; i< 5; i++)
    {
        cout << food[i] << endl;
    }

    // Allocate a single integer - allocates memory in heap
    int* p1 = new int;
    *p1 = 5;

    // Allocate and initialize 10 ints = 40 bytes
    int* p2 = new int(10);

    // Delete when done
    delete p1;
    delete p2;

    // example usage of function tempalate
    //int resultt = result(5, 3.2);
    cout << result(5, 3.2) << endl;
}

