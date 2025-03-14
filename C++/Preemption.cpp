#include <iostream>
#include <thread>
#include<stdio.h>
#include<unistd.h>


void taskA() {
    while (true) {
        printf("Task A running\n");
        sleep(1); // Simulating work
    }
}

void taskB() {
    while (true) {
        printf("Task B running\n");
        sleep(1); // Simulating work
    }
}

int main() {
    std::thread t1(taskA);
    std::thread t2(taskB);
    
    t1.join();
    t2.join();
}
