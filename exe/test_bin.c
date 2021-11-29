#include <stdio.h>
#include <stdlib.h>
#include "arbre_bin.h"

int main(void)
{
    arbre a = creer_noeud(element_new("racine"));
    arbre c = a;
    char temp[254];

    for (int i = 0; i < 10; i++)
    {
        sprintf(temp, "%d", i);
        c->frere = creer_noeud(element_new(temp));
        c->fils = creer_noeud(element_new(temp));
        c = c->fils;
    }
    
    if(arbre_est_vide(a))
        printf("erreur");
    

    printf("hauteur : %u\tnb_noeuds : %u\tfeuilles : %u\n", hauteur(a), nb_noeuds(a), nb_feuilles(a));
    
    parcours_prefixe(a);
    printf("\n");
    detruire_arbre(a);
    return EXIT_SUCCESS;
}
