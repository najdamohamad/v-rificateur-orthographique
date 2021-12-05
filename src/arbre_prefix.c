#include "arbre_bin.h"

bool recherche_arbre_prefix(arbre a, elem e){

    arbre c = a;
    int nb_fils = 0, e_l;

    // if(strcmp(e->mot, "bruire") == 0)
    //     getchar();

    while (!arbre_est_vide(c))
    {   
        e_l = element_length(c->val);

        if(strncmp(c->val->mot, e->mot + nb_fils, e_l) == 0)
        {
            nb_fils += e_l;
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
    arbre* p = a,* c = a, i, *tmp;
    bool est_frere = false, insere = false;
    int nb_fils = 0;

    while (!arbre_est_vide(*c))
    {
        if(element_get((*c)->val, 0) == element_get(e, nb_fils))
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
            //Insertion pour trier l'arbre
            if(element_get(e, nb_fils) < element_get((*c)->val, 0))
            {
                i = *c;
                insere = true;
                break;
            }

            est_frere = true;
            p = c;
            c = &(*c)->frere;
        }
    }
        
    
    //premier cas depend de la position du precedent
    char *pChar = calloc(2, sizeof(char));
    
    *pChar = element_get(e, nb_fils);
    elem new = element_new(pChar);

    if(*a == NULL || c == a)
    {
        *c = creer_noeud(new);
        tmp = c;
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
        tmp = p;
    }

    //le reste est forcement fils
    while(element_get(e, ++nb_fils) != '\0')
    {
        *pChar = element_get(e, nb_fils);
        new = element_new(pChar);
        (*c)->fils = creer_noeud(new);
        p = c;
        c = &((*c)->fils);
    }

    (*c)->final = true;

    if(insere)
    {
        (*tmp)->frere = i;
    }

    free(pChar);
            
}

bool verifArbre(char* mot, void* struct_donne)
{
    elem e = element_new(mot);

    if(!recherche_arbre_prefix(struct_donne, e))
    {
        //printf("%s\n", mot);
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
    element_delete(e);
}