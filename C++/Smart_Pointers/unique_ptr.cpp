#include<iostream>
#include<memory>
#include <mutex>

using namespace std;


//Mutex initialization - no need to release the lock, it will automatically release it
// RAII Resource Acquisition Is Initialization
mutex mtx;

void safeFunction() {
    lock_guard<mutex> lock(mtx); // Automatically locks
    cout << "Thread-safe execution" << endl;
} // lock is released when `lock_guard` goes out of scope

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

// one ptr has ownership, can not be copied - only move operation is possible to switch the ownership



int main()
{
    
    {
        unique_ptr<human> h = make_unique<human>();
        // unique_ptr<human> copy_h = h;    will throw error
        unique_ptr<human>move_h = move(h);  //will change the ownership to the move_h now
        h -> print_class();    

        
    } // will automatically free the memory used by unique_ptr - called as RAII
}