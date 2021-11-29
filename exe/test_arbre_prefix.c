#include <stdio.h>
#include <stdlib.h>
#include "arbre_prefix.h"
#include "arbre_radix.h"
int main(void)
{
    arbre a = NULL;
    
    elem e1 = element_new("coucou");
    elem e2 = element_new("salut");
    elem e3 = element_new("couture");
    elem e4 = element_new("s");
    elem e5 = element_new("boom");
    elem e6 = element_new("cout");
    elem e7 = element_new("a");

    
    //ajout_prefix(&a, e2);
    ajout_prefix(&a, e7);
    ajout_prefix(&a, e4);
    ajout_prefix(&a, e1);
    ajout_prefix(&a, e3);
    ajout_prefix(&a, e5);

    parcours_prefixe(a);

    printf("\ncoucou : %d, salut : %d, couture : %d, s %d,boom %d, cout %d, a %d\n",   
                                        recherche_arbre_prefix(a , e1), 
                                        recherche_arbre_prefix(a , e2),
                                        recherche_arbre_prefix(a , e3),
                                        recherche_arbre_prefix(a , e4),
                                        recherche_arbre_prefix(a , e5),
                                        recherche_arbre_prefix(a , e6),
                                        recherche_arbre_prefix(a , e7));

    transform_prefix_into_radix(&a);
    parcours_prefixe(a);

    printf("\ncoucou : %d, salut : %d, couture : %d, s %d,boom %d, cout %d, a %d\n",   
                                        recherche_arbre_prefix(a , e1), 
                                        recherche_arbre_prefix(a , e2),
                                        recherche_arbre_prefix(a , e3),
                                        recherche_arbre_prefix(a , e4),
                                        recherche_arbre_prefix(a , e5),
                                        recherche_arbre_prefix(a , e6),
                                        recherche_arbre_prefix(a , e7));

    element_delete(e1);
    element_delete(e2);

    detruire_arbre(a);
    return EXIT_SUCCESS;
}
