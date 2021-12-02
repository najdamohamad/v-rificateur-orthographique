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

void partage_prefix(arbre* a, liste* alr_meet, liste* duplic)
{
    if(*a == NULL)
        return;
    
    partage_prefix(&((*a)->fils), alr_meet, duplic);
    partage_prefix(&((*a)->frere), alr_meet, duplic);

    if((*a)->final == false)
        return;

    arbre* noeud = liste_element_exist(a, *alr_meet, noeud_cmp);
    printf("mot : %s", (*a)->val->mot);
    getchar();

    if(noeud == NULL)
    {
        liste_add_first(a, alr_meet);
        printf("add list : %s\n", (*a)->val->mot);
    }
    else
    {
        liste_add_first(noeud, duplic);
        arbre tmp = *a;

        //on ajoute les frères du fils a la suite du nouveau fils
        arbre* t = &(*noeud)->fils;
        
        if(*t != NULL)
        {
            printf("%s\n", (*t)->val->mot);
            while ((*t)->frere != NULL)
            {
                t = &(*t)->frere;
            }
            (*t)->frere = (*a)->fils;
        }

        a = noeud;

        element_delete(tmp->val);
        free(tmp);
    }
        
}

void radix_list_delete(void* e)
{
    printf("%p : %s\n", e, ((*(arbre*)e))->val->mot);
    element_delete((*((arbre*)e))->val);
    free(*((arbre*)e));
}

void detruire_arbre_radix(arbre* a, liste l)
{
    if(arbre_est_vide(*a))
        return;

    detruire_arbre_radix(&(*a)->frere, l);
    detruire_arbre_radix(&(*a)->fils, l);

    arbre* noeud = liste_element_exist(a, l, noeud_cmp);

    printf("noed : %p\n", noeud);
    if(noeud == NULL)
    {
        element_delete((*a)->val);
        free(*a);
    }
}