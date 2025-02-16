// Bit fields are used to save space. 

#include<stdio.h>

#define LOG_YES 0b01  // 1
#define LOG_NO  0b10  // 2
#define LOG_BOTH 0b11

// Usage - 1 Bit feilds can be used to give options
int some_func(int options);

// Usecase 2 : For parameters that takes too much place than needed
// Example - Suppose I need variable for student's Midterm exam whhich never going to need 32 bits
struct counters{
    int little:2;
    int medium:4;
    int large:6;
}__attribute__((packed));


int main()
{
    struct counters c;
    for(int i = 0; i < 50; i++)
    {
        c.little++;
        c.medium++;
        c.large++;
        // as we can see - c.little takes only 2 bits and its int so it goes from -2 to 1, similarlly
        // for others - try changing it to uint to have a better idea
        // if they were unsigned int - little range will go from 0 to 3 because it is of 2 bits
        printf("%d  %d  %d\n", c.little, c.medium, c.large);
    };

    // It will be 4 bytes - Compiler will align it instead of packing it in memory
    //printf("sizeof(struct counters c) %d Bytes - Before any optimization\n", sizeof(c));

    // After optimizing it with attribute_packed - it will be 2 bytes (2 + 6 + 12) bits
    printf("sizeof(struct counters c) %d Bytes - After any optimization\n", sizeof(c));

    some_func(LOG_YES | LOG_NO);
    some_func(LOG_NO);
    // some_func(LOG_BOTH);
}

int some_func(int options)
{
    if(options & LOG_YES)
    {
        printf("YES ");
    }
    if(options & LOG_NO)
    {
        printf("NO ");
    }
    // not usefull as per my understanding
    // if(options & LOG_BOTH)
    // {
    //     printf("YES NO ");
    // }
    printf("\n");
}

