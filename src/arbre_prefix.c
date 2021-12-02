#include "arbre_bin.h"

bool recherche_arbre_prefix(arbre a, elem e){

    arbre c = a;
    int nb_fils = 0, e_l;

    while (!arbre_est_vide(c))
    {   
        e_l = element_length(c->val);
        if(element_compare_n_to_m(c->val, e, nb_fils, e_l) == 0)
        {
            nb_fils = e_l;
            //On vérifie que la prochaine lettre du mot n'est pas \0
            if(element_get(e, nb_fils) == '\0')
            {
                if(c->final)
                    return true;
                else
                    return false;
            }
            c = c->fils;
        }
        else
            c = c->frere;
    }
    
    return false;
}

void ajout_prefix(arbre* a, elem e)
{
    arbre* p = a,* c = a;
    bool est_frere = false;
    int nb_fils = 0;

    while (!arbre_est_vide(*c))
    {
        if(element_compare_n_to_m((*c)->val, e, nb_fils, nb_fils+1) == 0)
        {
            //On vérifie que la prochaine lettre du mot n'est pas \0
            if(element_get(e, ++nb_fils) == '\0')
            {
                (*c)->final = true;
                return;
            }

            est_frere = false;
            p = c;
            c = &(*c)->fils;
        }
        else
        {
            est_frere = true;
            p = c;
            c = &(*c)->frere;
        }
    }
        
    
    //premier cas depend de la position du precedent
    elem new = element_copy_n(e, ++nb_fils);
    if(*a == NULL)
    {
        *a = creer_noeud(new);
    }
    else
    {
        if(est_frere)
        {
            (*p)->frere = creer_noeud(new);
            p = &(*p)->frere;
        }
        else    
        {
            (*p)->fils = creer_noeud(new);
            p = &(*p)->fils;
        }
    }

    //le reste est forcement fils
    while(element_get(e, nb_fils) != '\0')
    {
        nb_fils++;
        new = element_copy_n(e, nb_fils);
        (*c)->fils = creer_noeud(new);
        p = c;
        c = &((*c)->fils);
    }

    (*c)->final = true;
            
}

bool verifArbre(char* mot, void* struct_donne)
{
    elem e = element_new(mot);

    if(!recherche_arbre_prefix(struct_donne, e))
    {
        printf("%s\n", mot);
        element_delete(e);
        return false;
    }
    element_delete(e);
    return true;
}

void lectureArbre(char* mot, void* struct_donne)
{
    elem e = element_new(mot);
    ajout_prefix(struct_donne, e);
}