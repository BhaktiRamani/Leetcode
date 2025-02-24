#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void *my_memset(void *src, const void*data, size_t nbytes);


int main()
{
     // Allocate memory for the string, ensure it's large enough
    // char* str = (char*)malloc(6 * sizeof(char));  // Allocate 6 bytes (5 for characters + 1 for null terminator)
    
    // if (str == NULL) {  // Always check malloc success
    //     printf("Memory allocation failed\n");
    //     return 1;
    // }

    char str[5] = "";
    // Set memory
    my_memset(str, "A", 5);

    printf("%s\n", str);

   
    // free(str);

    return 0;
}
void *my_memset(void *destination, const void*data, size_t nbytes)
{
    char *dest = (char*)destination;
    const char* val = (const char*)data;
    
    for(int i = 0; i<nbytes; i++)
    {
        *dest = *val;
        dest++;

    }
    *dest = '\0';
}