#include <stdio.h>


// Alternative implementation using pointer arithmetic
int my_memcmp_ptr(const void* ptr1, const void* ptr2, size_t num) {
    const unsigned char* s1 = (const unsigned char*)ptr1;
    const unsigned char* s2 = (const unsigned char*)ptr2;
    
    while(num-- > 0)
    {
        if(*s1 != *s2)
            return (*s1 < *s2) ? -1 : 1;
        s1++;
        s2++;
    }
    return 0;
}