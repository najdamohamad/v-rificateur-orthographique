#include "arbre_radix.h"


void transform_prefix_into_radix(arbre* a)
{
    if(*a == NULL)
        return;

    transform_prefix_into_radix(&(*a)->fils);

    transform_prefix_into_radix(&(*a)->frere);

    if((*a)->final == false && (*a)->fils != NULL && (*a)->fils->frere == NULL)
    {
        element_delete((*a)->val);
        (*a)->val = (*a)->fils->val;
        (*a)->final = (*a)->fils->final;

        arbre tmp = (*a)->fils;
        (*a)->fils = (*a)->fils->fils;
        
        free(tmp);
    }
}