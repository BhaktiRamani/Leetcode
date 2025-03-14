#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

std::atomic_flag spinlock = ATOMIC_FLAG_INIT;

void lock() {
    while (spinlock.test_and_set(std::memory_order_acquire));  // Busy wait
}

void unlock() {
    spinlock.clear(std::memory_order_release);
}


// Shared resource
int shared_counter = 0;

void increment_counter(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Start critical section
        lock();
        
        // Access shared resource
        shared_counter++;
        
        // End critical section
        unlock();
    }
}

int main() {
    const int num_threads = 4;
    const int iterations_per_thread = 100000;
    
    std::vector<std::thread> threads;
    
    // Create threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(increment_counter, iterations_per_thread));
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    // Verify the result
    std::cout << "Expected final counter: " << num_threads * iterations_per_thread << std::endl;
    std::cout << "Actual final counter: " << shared_counter << std::endl;
    
    return 0;
}





