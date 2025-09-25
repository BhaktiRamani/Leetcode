#include<stdio.h>
#include<pthread.h>

int x, y = 0;
int cntr = 0;
void* func1()
{
    x = 3;
    printf("x : %d , y : %d cntr : %d\n", x,y, cntr);

    for(int i=0;i<100;i++){
        cntr++;
    }

    return NULL;
}
void* func2()
{
    y = x;
    for(int i=0;i<100;i++){
        cntr++;
    }
    printf("x : %d , y : %d , cntr : %d \n", x,y, cntr);

    return NULL;
}

// running this program multiple times can lead to data race and it's easy to not see that behaviour because program or thread work is very small. 
int main()
{
    int *ptr;
    int y; 
    if(ptr != NULL)
    {
        y = *ptr; 
        printf("%d\n", y);
    }

    pthread_t t1; 
    pthread_t t2;

    pthread_create(&t1, NULL, &func1, NULL); 
    pthread_create(&t2, NULL, &func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final x : %d , y : %d , cntr : %d \n", x,y, cntr);
}

