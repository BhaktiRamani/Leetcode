#include<iostream>
#include<pthread.h>

using namespace std;

void *print_msg(void*){
    cout << "This is print_msg" << endl;
    return nullptr;
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, nullptr, print_msg, nullptr);
    pthread_join(thread_id, nullptr);

    
}