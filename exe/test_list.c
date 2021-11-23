#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{

    liste ltest = create_liste();
    
    add_first(element_new("3"), &ltest);
    add_first(element_new("2"), &ltest);
    add_first(element_new("1"), &ltest);

    afficher(ltest);

    add_last(element_new("4"), &ltest);
    add_last(element_new("5"), &ltest);
    add_last(element_new("6"), &ltest);

    afficher(ltest);
    destroy(ltest);
    
    return 0;
}
