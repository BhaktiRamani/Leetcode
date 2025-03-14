#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t sem;
using namespace std;
void worker(int id) {

    sem_wait(&sem);  // Decrement semaphore (wait)
    std::cout << "Thread " << id << " is in critical section\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate work
    sem_post(&sem);  // Increment semaphore (signal)
}

int main() {
    sem_init(&sem, 0, 2);  // Allow up to 2 threads at a time   semaphore value = 2
    std::thread t1(worker, 1);  // 1 , 2 ,3 are parameters passed to thread
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);

    t1.join(); t2.join(); t3.join();
    sem_destroy(&sem);
    return 0;
}
