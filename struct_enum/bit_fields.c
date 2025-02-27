/*bit fields are use to reduce the size of struct. 
suppose I have one variable int bt it ranges from 0 to  3 only. If i only use 2 bits for that
- still it will work fine and help me save memory too.
*/

#include<stdio.h>

// here normally unsigned int takes 4 bytes so this structure size should be 8 bytes
// but by using bit fields - it is still 4 bytes and not 8 !!

typedef struct bit_fields{
    unsigned int bits : 2;
    unsigned int bit3 :3;
}bit_t;

int main()
{
    bit_t bt;
    bt.bits = 2;
    bt.bit3 = 5;
    printf("bt.bits = %d sizeof struct = %ld\n", bt.bits, sizeof(bt));
}