#include "arbre_bin.h"

bool recherche_arbre_prefixe(arbre a, elem e){

    arbre c = a;
    int nb_fils = 0;

    while (!arbre_est_vide(c))
    {   
        
        if(element_compare_n(c->val, e, nb_fils) == 0)
        {
            nb_fils ++ ;
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

void ajout_prefix(arbre a, elem e)
{
    arbre p, c = a;
    bool est_frere = false;
    int nb_fils = 0;

    while (!arbre_est_vide(c))
    {   
        
        if(element_compare_n(c->val, e, nb_fils) == 0)
        {
            nb_fils ++ ;
            //On vérifie que la prochaine lettre du mot n'est pas \0
            if(element_get(e, nb_fils) == '\0')
            {
                c->final = true;
            }

            est_frere = false;
            p = c;
            c = c->fils;
        }
        else
        {
            est_frere = true;
            p = c;
            c = c->frere;
        }
    }
    
    //// a creer un premier elemeent 
    
    elem new = element_copy_n(e,nb_fils);

    if(est_frere)
        p->frere = creer_noeud(new);
    else
    {
        while(!c->final)
        {
            p->fils = creer_noeud(new);
            if(element_get(e, nb_fils) == '\0')
            {
                c->final = true;
                break ;
            }
            new = element_copy_n(e,nb_fils++); 
            p = c ;
            c = c->fils ;

        }
            

}