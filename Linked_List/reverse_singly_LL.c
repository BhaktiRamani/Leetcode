

#include "ll.h"

int main()
{
    ll_ptr_t ll = create_head(64, 1);
    append(ll, 2);
    append(ll, 3);
    append(ll, 4);
    append(ll, 5);

    // push(ll, 0);
    // pop(ll);
    // pull(ll);
    print_LL(ll);


    ll_t *ll2 = create_head(64, 1);
    append(ll2, 2);
    append(ll2, 3);
    append(ll2, 4);
    append(ll2, 5);

    // push(ll, 0);
    // pop(ll);
    // pull(ll);
    print_LL(ll2);



    return 0;


}


