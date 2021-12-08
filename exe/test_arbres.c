#include <stdio.h>
#include <stdlib.h>
#include "arbre_prefix.h"
#include "arbre_radix.h"
int main(void)
{
    arbre a = NULL;
    
    elem e1 = element_new("coucou");
    elem e2 = element_new("boomier");
    elem e3 = element_new("couture");
    elem e4 = element_new("boomer");
    elem e5 = element_new("boomettes");
    elem e6 = element_new("boom");
    elem e7 = element_new("couturier");
    elem e8 = element_new("boome");
    elem e9 = element_new("couturettes");
    elem e10 = element_new("courgette");

    
    //ajout_prefix(&a, e2);
    ajout_prefix(&a, e1);
    ajout_prefix(&a, e2);
    ajout_prefix(&a, e3);
    ajout_prefix(&a, e4);
    ajout_prefix(&a, e5);
    ajout_prefix(&a, e6);
    ajout_prefix(&a, e7);
    ajout_prefix(&a, e8);
    ajout_prefix(&a, e9);

    parcours_prefixe(a); printf("\n");

    printf("%s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n",   
                                        e1->mot, recherche_arbre_prefix(a , e1), 
                                        e2->mot, recherche_arbre_prefix(a , e2),
                                        e3->mot, recherche_arbre_prefix(a , e3),
                                        e4->mot, recherche_arbre_prefix(a , e4),
                                        e5->mot, recherche_arbre_prefix(a , e5),
                                        e6->mot, recherche_arbre_prefix(a , e6),
                                        e7->mot, recherche_arbre_prefix(a , e7),
                                        e8->mot, recherche_arbre_prefix(a , e8),
                                        e9->mot, recherche_arbre_prefix(a , e9),
                                        e10->mot, recherche_arbre_prefix(a , e10));

    transform_prefix_into_radix(&a);
    parcours_prefixe(a); printf("\n");

    table_hachage ht = hash_new(1);
    bool useless;
    a = partage_suffix(a, &ht, &useless);
    //On peut libérer la mémoire de la table sans supprimer les éléments
    hash_destroy(&ht, chuuuuuu);

    parcours_prefixe(a); printf("\n");

    printf("%s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d, %s : %d\n",   
                                        e1->mot, recherche_arbre_prefix(a , e1), 
                                        e2->mot, recherche_arbre_prefix(a , e2),
                                        e3->mot, recherche_arbre_prefix(a , e3),
                                        e4->mot, recherche_arbre_prefix(a , e4),
                                        e5->mot, recherche_arbre_prefix(a , e5),
                                        e6->mot, recherche_arbre_prefix(a , e6),
                                        e7->mot, recherche_arbre_prefix(a , e7),
                                        e8->mot, recherche_arbre_prefix(a , e8),
                                        e9->mot, recherche_arbre_prefix(a , e9),
                                        e10->mot, recherche_arbre_prefix(a , e10));

    element_delete(e1);
    element_delete(e2);
    element_delete(e3);
    element_delete(e4);
    element_delete(e5);
    element_delete(e6);
    element_delete(e7);
    element_delete(e8);
    element_delete(e9);
    element_delete(e10);

    printf("%ld, %ld ,%ld\n", sizeof(a), sizeof(a->fils), sizeof(a->final));


    //Liste pour la libération mémoire
    table_hachage duplic = hash_new(1);
    detruire_arbre_radix(a, &duplic);
    hash_destroy(&duplic, radix_delete);

    return EXIT_SUCCESS;
}
