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

arbre partage_suffix(arbre a, table_hachage* alr_meet, bool* reloc)
{
    bool reloc_frer, reloc_fils;
    arbre noeud = NULL;

    if(a == NULL)
    {
        *reloc = true;
        return NULL;
    }
    
    a->frere = partage_suffix(a->frere, alr_meet, &reloc_frer);
    a->fils = partage_suffix(a->fils, alr_meet, &reloc_fils);

    //Si le frère et le fils sont relocalisé, il y a des chances que le père aussi
    if(reloc_fils && reloc_frer)
    {
        noeud = hash_est_present(a, alr_meet, hash_suffix, suffix_compare);
    }
        
    //Si le préfixe n'existe pas dans les anciens rencontrés
    if(noeud == NULL)
    {
        hash_inserer_redimensionner(a, alr_meet, hash_suffix, suffix_compare);
        //Indicateur pour les pères
        *reloc = false;
        return a;
    }
    else
    {
        //Indicateur pour les pères
        *reloc = true;
        //On marque le noeud pour la libération
        noeud->reloc = true;

        //Suppression du neud inutile
        element_delete(a->val);
        free(a);
        
        //Noeud compressé
        return noeud;
    }
}

void radix_delete(void* e)
{
    element_delete(((arbre)e)->val);
    free((arbre)e);
}

void detruire_arbre_radix(arbre a, table_hachage* duplic)
{
    if(arbre_est_vide(a))
        return;

    detruire_arbre_radix(a->frere, duplic);
    detruire_arbre_radix(a->fils, duplic);
    
    //On ne supprime pas tout de suite les doublons : on les places dans une liste
    //pour supprimer les doubles et les erreurs de double free
    if(a->reloc == true)
    {
        if(hash_est_present(a, duplic, hash_suffix, suffix_compare) == NULL)
            hash_inserer_redimensionner(a, duplic, hash_suffix, suffix_compare);
    }
    else
    {
        element_delete(a->val);
        free(a);
    }
}

int suffix_compare(void* e1, void* e2)
{
    if(strcmp(((arbre)e1)->val->mot, ((arbre)e2)->val->mot) == 0 && ((arbre)e1)->final == ((arbre)e2)->final)
    {
        if(((arbre)e1)->fils == ((arbre)e2)->fils && ((arbre)e1)->frere == ((arbre)e2)->frere)
            return 0;
    }
    return -1;
}

int hash_suffix(void* e, unsigned c)
{
    int hash = hash_str(((arbre)e)->val, c);
    return hash;
}