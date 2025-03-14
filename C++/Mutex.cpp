#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int counter = 0;

void increment() {

    //std::lock_guard<std::mutex> lock(mtx); // bettter - no need to release the mutex
  //  mtx.lock();
    counter++;  // Critical section
    // mtx.unlock();
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter << std::endl;


    

}
