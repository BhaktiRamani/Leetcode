#include<stdio.h>

void *my_memcpy(void *to, const void *from, size_t numBytes);

int main()
{
   
    int src_array[] = {1, 2, 2, 2, 4, 5};
    int dest_array[5];
    my_memcpy(dest_array, src_array, sizeof(int) * 5);  
    for(int i = 0; i<5; i++)
    {
            printf("%d  ", dest_array[i]);
    }

}

void *my_memcpy(void* destination, const void *source, size_t numBytes)
{
   
    char *d = (char*)destination;
    const char *s = (const char*)source;
    for(size_t i = 0; i<numBytes; i++)
    {
        *d = *s;
        d++;
        s++;
       
    }
    


}