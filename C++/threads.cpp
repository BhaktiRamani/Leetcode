#include<iostream>
#include<thread>

using namespace std;


void func1(void){
    cout << "This is func 1" << endl;
    for(int i = 0; i<1000000000; i++){}
}

int add(int a, int b)
{
    cout << a+b << endl;
    return 0;
}

void deteched(void){
    cout << "This is a deteched thread" << endl;
    
}

int main()
{
    thread func1_t(func1);        // creating a thread
    cout << "Waiting" << endl;
    func1_t.join();                 // wait for thread to finish
    cout << "Func1 done" << endl;   // it will get printed after some time - after finishing the thread func    - if join is not used - it will get interrupted with this cout statement and mission abort


    thread add_t(add, 2, 3);
    add_t.join();

    thread deteched_t (deteched);
    deteched_t.detach();        // main thread will run before finishing up the task for this thread
  
}