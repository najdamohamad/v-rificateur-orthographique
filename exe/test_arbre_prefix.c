#include <stdio.h>
#include <stdlib.h>
#include "arbre_prefix.h"

int main(void)
{
    arbre a = NULL;
  
    ajout_prefix(a, element_new("coucou"));

    printf("fin entrees\n");
    getchar();

    printf("coucou : %d, salut : %d",   recherche_arbre_prefix(a , element_new("coucou")), 
                                        recherche_arbre_prefix(a , element_new("salut")));

    detruire_arbre(a);
    return EXIT_SUCCESS;
}
