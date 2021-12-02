#include "arbre_bin.h"

//FONCTIONS GENERIQUES
noeud* creer_noeud(elem valeur)
{
    noeud* n = calloc(1, sizeof(*n));

    n->frere = NULL;
    n->fils = NULL;
    n->final = false;
    n->val = valeur;

    return n;
}

bool arbre_est_vide(arbre a)
{
    return a == NULL;
}

void detruire_arbre(arbre a)
{
    if(arbre_est_vide(a))
        return;

    detruire_arbre(a->frere);
    detruire_arbre(a->fils);

    element_delete(a->val);
    free(a);
}

unsigned hauteur(arbre a)
{
    if(arbre_est_vide(a))
        return 0;
    
    unsigned hd = 0, hg = 0;
    
    if(!arbre_est_vide(a->frere))
    {
        hd++;
        hd += hauteur(a->frere);
    }
    if(!arbre_est_vide(a->fils))
    {
        hg++;
        hg += hauteur(a->fils);
    }

    return hd > hg ? hd : hg;
}

unsigned nb_noeuds(arbre a)
{
    if(arbre_est_vide(a))
        return 0;

    unsigned n = 1;
    
    n += nb_noeuds(a->frere);
    n += nb_noeuds(a->fils);
        
    return n;
}

unsigned nb_feuilles(arbre a)
{
    if(arbre_est_vide(a))
        return 0;
    if(arbre_est_vide(a->fils) && arbre_est_vide(a->frere))
        return 1;
    
    unsigned n = 0;
    
    n += nb_feuilles(a->frere);
    n += nb_feuilles(a->fils);
    
    return n;
}

bool arbre_est_degenere(arbre a)
{
    return nb_feuilles(a) == 1 ? true : false;
}

bool arbre_est_parfait(arbre a)
{
    if(arbre_est_vide(a))
        return false;

    return nb_feuilles(a) == (unsigned)(0b1 << hauteur(a)) ? true : false;
}

void parcours_prefixe(arbre a)
{
    if(arbre_est_vide(a))
        return;

    printf("(");
    element_print(a->val);
    if(a->final)
        printf(" f"); 
    printf(")->");

    parcours_prefixe(a->fils);
    parcours_prefixe(a->frere);   
}

int noeud_cmp(void* a1, void* a2)
{
    return element_compare(((arbre)a1)->val, ((arbre)a2)->val);
}