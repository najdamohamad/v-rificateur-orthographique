#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void)
{

    liste ltest = liste_create();
    
    elem e1 = element_new("3");

    liste_add_first(e1, &ltest);
    liste_add_first(element_new("2"), &ltest);
    liste_add_first(element_new("1"), &ltest);

    liste_afficher(ltest);

    liste_add_last(element_new("4"), &ltest);
    liste_add_last(element_new("5"), &ltest);
    liste_add_last(element_new("6"), &ltest);

    liste_afficher(ltest);

    printf("Taille mémoire du pointeur liste : %ld, elem : %ld et %ld, pointeur next %ld\n", sizeof(ltest), sizeof(ltest->e), sizeof(e1->mot), sizeof(ltest->next));
    
    
    
    liste_destroy(ltest, element_delete);

    return 0;
}
