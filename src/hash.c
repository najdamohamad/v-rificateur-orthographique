#include "hash.h"

//FONCTIONS GENERIQUES

table_hachage new_hash(unsigned capacite)
{
    table_hachage ht;
    ht.capacite = capacite;
    ht.capacite_initiale = capacite;
    ht.nb_elements = 0;
    ht.table = calloc(ht.capacite, sizeof(*ht.table));
    unsigned int i;
    for(i=0;i<ht.capacite;i++)
    {
        ht.table[i] = NULL;
    }
    return ht;
}

int hash(T element, unsigned capacite)
{
    int h = 0;
    int a = 33;
    int l = element_length(element);

    for(int i=0; i<l; i++)
    {
        h = h * a + element_get(element, l-i-1);
    }

    return h % capacite;
}

bool hash_identiques(T element_1, T element_2)
{
    return element_compare(element_1, element_2);
}

bool est_present(T element, table_hachage* ht)
{
    int h = hash(element, ht->capacite);
    
    liste l = ht->table[h];

    while (l != NULL)
    {
        if(hash_identiques(element, l->element) == 0)
            return 1;
        
        l = l->suivante;
    }
    
    return 0;
}

void inserer_sans_redimensionner(T element, table_hachage* ht)
{
    if(!est_present(element, ht))
    {
        int h = hash(element, ht->capacite);
        ht->nb_elements++;

        liste l = calloc(1, sizeof(*l));
        l->element = element;
        l->suivante = ht->table[h];
        ht->table[h] = l;
    }
}

void inserer_redimensionner(T element, table_hachage* ht)
{
    if(ht->nb_elements > 2*ht->capacite/3)
    {
        table_hachage new_ht = new_hash(ht->capacite*2);
        
        //Copie de tous les éléments
        unsigned int i;
        liste l;
        for(i=0;i<ht->capacite;i++)
        {
            l = ht->table[i];
            while (l != NULL)
            {
                inserer_sans_redimensionner(element_copy(l->element), &new_ht);
                l = l->suivante;
            }
        }

        destroy_hash(ht);
        *ht = new_ht;
    }
    
    inserer_sans_redimensionner(element, ht);
}

void afficher_table(table_hachage* ht)
{
    unsigned int i;
    liste l;
    printf("{");
    for(i=0;i<ht->capacite;i++)
    {
        l = ht->table[i];
        printf("[");
        while (l != NULL)
        {
            element_print(l->element);
            
            l = l->suivante;
        }
        printf("]\n");
    }
    printf("}\n");
}

void destroy_hash(table_hachage* ht)
{
    unsigned int i;
    liste l, tmp;
    for(i=0;i<ht->capacite;i++)
    {
        l = ht->table[i];
        while (l != NULL)
        {
            tmp = l;
            l = l->suivante;
            element_delete(tmp->element);
            free(tmp);
        }
    }
    free(ht->table);
}