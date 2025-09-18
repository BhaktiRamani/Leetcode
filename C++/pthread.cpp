#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void *print_msg(void*){
    cout << "This is print_msg" << endl;
    return nullptr;
}

void *myturn( void *arg)
{
    int *param = (int *)arg;
    int *ret = new int(10);
    for(int i = 0; i<10; i++)
    {
        sleep(1);
        printf("%d : My Turn! %d\n", i, *param);
        (*ret)++;
        (*param)++;
    }
    return (void *)ret;
}

void *yourturn(void *arg)
{
    for(int i = 0; i< 4; i++)
    {
        sleep(2);
        printf("Your Turn!\n");
    }
    return NULL;
}

int main()
{
    // pthread_t thread_id;
    // pthread_create(&thread_id, nullptr, print_msg, nullptr);
    // pthread_join(thread_id, nullptr);

    int *param = new int(5);
    pthread_t myturn_t;

    pthread_create(&myturn_t, NULL, myturn, param);

    // myturn(NULL);
    yourturn(NULL);
    int ret = (int)pthread_join(myturn_t, nullptr);

    printf("Returned value is : %d\n", ret);
 
}