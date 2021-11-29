#include <stdio.h>
#include <stdlib.h>
#include "arbre_bin.h"

int main(void)
{
    arbre a = NULL;
    if(arbre_est_vide(a))
        a = creer_noeud(0);
    
    a->frere = creer_noeud(4);
    a->fils = creer_noeud(1);
    a->fils->frere = creer_noeud(3);
    a->fils->fils = creer_noeud(2);
    a->frere->frere = creer_noeud(5);
    
    if(arbre_est_vide(a))
        printf("erreur");
    

    printf("hauteur : %u\tnb_noeuds : %u\tfeuilles : %u\tparfait ? %d\tdegenere ? %d\n", hauteur(a), nb_noeuds(a), nb_feuilles(a), arbre_est_parfait(a), arbre_est_degenere(a));
    
    parcours_infixe(a);

    detruire_arbre(a);
    return EXIT_SUCCESS;
}
