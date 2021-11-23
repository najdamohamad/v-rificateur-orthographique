#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{

    liste ltest = liste_create();
    
    liste_add_first(element_new("3"), &ltest);
    liste_add_first(element_new("2"), &ltest);
    liste_add_first(element_new("1"), &ltest);

    liste_afficher(ltest);

    liste_add_last(element_new("4"), &ltest);
    liste_add_last(element_new("5"), &ltest);
    liste_add_last(element_new("6"), &ltest);

    liste_afficher(ltest);
    liste_destroy(ltest);

    return 0;
}
