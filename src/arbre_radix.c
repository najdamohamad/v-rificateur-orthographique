#include "arbre_radix.h"


void transform_prefix_into_radix(arbre* a)
{
    if(*a == NULL)
        return;

    transform_prefix_into_radix(&(*a)->fils);

    transform_prefix_into_radix(&(*a)->frere);

    if((*a)->final == false && (*a)->fils != NULL && (*a)->fils->frere == NULL)
    {
        char tmp_c[30];
        strcpy(tmp_c, (*a)->val->mot);
        strcat(tmp_c,(*a)->fils->val->mot);
        elem new = element_new(tmp_c);

        element_delete((*a)->val);
        element_delete((*a)->fils->val);
        (*a)->val = new;

        (*a)->final = (*a)->fils->final;

        arbre tmp = (*a)->fils;
        (*a)->fils = (*a)->fils->fils;
        
        free(tmp);
    }
}

void chuuuuuu(void* e)
{
    return;
}


arbre partage_prefix(arbre a, liste* alr_meet, liste* duplic)
{
    if(a == NULL)
        return NULL;
    
    a->frere = partage_prefix(a->frere, alr_meet, duplic);
    a->fils = partage_prefix(a->fils, alr_meet, duplic);
    
    a->prefix = prefix_conc(a);
    
    if(a->final == false)
        return a;

    arbre noeud = liste_element_exist(a, *alr_meet, prefix_compare);
    printf("mot : %s, prefix : %s\n", a->val->mot, a->prefix->mot);

    if(noeud == NULL)
    {
        liste_add_first(a, alr_meet);
        return a;
    }
    else
    {
        if(liste_element_exist(noeud, *duplic, prefix_compare) == NULL)
            liste_add_first(noeud, duplic);
        
        printf("%p\n", noeud);

        arbre* a_tmp = &noeud;
        while ((*a_tmp)->frere !=NULL)
        {
            a_tmp = &(*a_tmp)->frere;
        }
        (*a_tmp)->frere = a->frere;

        element_delete(a->val);
        element_delete(a->prefix);
        free(a);
        
        return noeud;
    }
        
}

elem prefix_conc(arbre a)
{
    char concaten[30000];
    concaten[0] = 0;
    arbre tmp;

    if(a != NULL)
    {
        //Pour éviter de faire les frères de a
        strcat(concaten, a->val->mot);
        a = a->fils;
    }
    while (a != NULL)
    {
        tmp = a;
        while (tmp != NULL)
        {
            strcat(concaten, tmp->val->mot);
            tmp = tmp->frere;
        }
        a = a->fils;
    }
    
    elem new = element_new(concaten);
    return new;
}

void radix_list_delete(void* e)
{
    element_delete(((arbre)e)->val);
    element_delete(((arbre)e)->prefix);
    free((arbre)e);
}

void detruire_arbre_radix(arbre a, liste l)
{
    if(arbre_est_vide(a))
        return;

    arbre noeud = liste_element_exist(a, l, noeud_cmp);

    if(noeud == NULL)
    {
        detruire_arbre_radix(a->frere, l);
        detruire_arbre_radix(a->fils, l);

        element_delete(a->val);
        element_delete(a->prefix);
        free(a);
    }
}

int prefix_compare(void* e1, void* e2)
{
    return element_compare(((arbre)e1)->prefix, ((arbre)e2)->prefix);
}