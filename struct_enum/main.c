#include<stdio.h>


 // if z = 1 then take y as mask and set all the bit in x with mask
// if z = 0 then take y as a position where i want to set the bit 
#define SET_BIT(x,y,z) ((z == 1) ? (( x | y )) : (( x | (1 << y))))


#define UNSET_BIT (x, y, z) (z == 1)? ((x & y)) : ((x & (1 << y)))

// if z = 1 then take y as mask and check if all the bit in x with mask is set or not
// if z = 0 then take y as a position and check if that position in x is set or not
#define CHECK_BIT (x, y, z) (z == 1) ? ((x) : ((x & (1 << y))))


// what machine I am on little endian = true , big endian = false (x == 1)
#define RETURN_ENDIENESS ({ \ 
 int x = 1; \
 char *ptr = (char *)&x;\
    (*ptr == 1);\
})


#define CHANGE_ENDIENESS(x) ({ \ 
    char *a = x; \
    char *b = x + sizeof(x); \
    for (int i = 0; i<sizeof(x)/2, a != b; i++){\
        *a = *a ^ *b;\
        *b = *a ^ *b;\
        *a = *a ^ *b;\ 
        a++;\
        b--;\
    }\
})

// container_of(struct data, z, 0x00)-> struct data x
#define container_of(structname, member, member_address)({  \
    const typeof(((structname *)(void *)0)->member) *__mptr = member_address;\
    (structname *)(member_address - (&((structname *)(void *)0)->member)); \
})





// container_of(struct data, z, 0x00)-> struct data x
#define container_of(structname, member, member_address) 


//poiter to a funtion to that pointes to a fnciton pointer that returns a pointer

// Stack

// string palindrome // effiencient 


// 2 rite linked list banavani

struct data
{
    int x;
    char y;
    float z;
    int *ptr;
};

struct data s = {
    .x = 1,
    .y = 2,
    .z = 3.0,
    .ptr = NULL,
};

typedef struct name{
    int x;
    char * str;
}name_t;

int main()
{
    char *a = "hello";
    printf("a : %s\n", a);
    char **aa = &a;
    printf("aa : %s\n", *aa);
    char ***aaa = &aa;
    printf("aa : %s\n", *aa);
    char b[2];

    char **A;
    char *B[2];

    char ***c;
    char ****d;

    printf("%p \n", &s.z);
    // struct data *p = container_of(struct data, z, &s.z);
    // printf("p->x %d\n", p->y);
 
    // int x = 3;
    // int *ptr = &x;
    // printf("Address x %p\n", ptr);
    // printf("Data x %d\n", *ptr);
    // printf("sizeof(ptr) %d\n", sizeof(*ptr));

    // float *address_f = &s.z;
    // printf("Address f %p\n", address_f);
    // printf("Sizeof s.z %d\n", sizeof(*address_f));

    // int *address_s = &s;
    // printf("Address s %p\n", address_s);

    // int *address_x = &s.x;
    // printf("data of s.x %d\n", *address_x);

    

    //printf("3, 4 %d\n", MIN(3,4,1) );
    // printf(" x = %d \n", SET_BIT(2, 3, 0));
    // printf("endianness : %d\n", RETURN_ENDIENESS);




    // union abc{
    //     float a;
    //     int b;
    // };
    // union abc a;
    // a.a = 1.0;
    
    // printf("a.a %f\n", a.a);
    // printf("float size %d\n", sizeof(float));
    // printf("int size %d\n",sizeof(int));
    // printf("address a.a %p\n", &a.a);
    // printf("address a.b %p\n", &a.b);
    // printf("a.b %d\n", a.b);



    // struct data d;
    // d.x = 2;
    // d.y = 'A';
    // d.z = 5.6;
    // int x = 10;
    // d.ptr = &x;

    // printf("d.x     %d\n", d.x);
    // printf("d.y     %c\n", d.y);
    // printf("d.z     %f\n", d.z);
    // printf("d.ptr   %d\n", (*d.ptr));


    // struct data *d2;
    // d2 = &d;
    // d2-> x = 2;
 
    // d2 -> y = 'A';
    // d2 -> z = 5.6;
    // int y = 10;
    // // d2 -> ptr = &y;

    // printf("d2 -> x     %d\n", d2 -> x);
    // printf("d2 -> y     %c\n", d2 -> y);
    // printf("d2 -> z     %f\n", d2 -> z);
    // printf("d2 -> ptr   %d\n", (*d2 ->ptr));

}
