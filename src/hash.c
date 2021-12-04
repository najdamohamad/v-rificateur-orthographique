#include "hash.h"

//FONCTIONS GENERIQUES

table_hachage hash_new(unsigned capacite)
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

int hash_str(void* element, unsigned capacite)
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

void* hash_est_present(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*))
{
    int h = hash_func(element, ht->capacite);
    
    liste l = ht->table[h];
    
    return liste_element_exist(element, l, cmp_func);
}

void hash_inserer_sans_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*))
{

    int h = hash_func(element, ht->capacite);
    ht->nb_elements++;
    liste_add_first(element, &ht->table[h]);
        
}

void hash_inserer_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*))
{
    if(ht->nb_elements > ht->capacite)
    {
        table_hachage new_ht = hash_new(ht->capacite*2);
        
        //Copie de tous les éléments
        unsigned int i;
        liste l;
        for(i=0;i<ht->capacite;i++)
        {
            l = ht->table[i];
            while (l != NULL)
            {
                hash_inserer_sans_redimensionner(l->e, &new_ht, hash_func, cmp_func);
                l = l->next;
            }
            liste_destroy(ht->table[i], empty);
        }
    
        free(ht->table);
        *ht = new_ht;
    }
    
    hash_inserer_sans_redimensionner(element, ht, hash_func, cmp_func);
}

void hash_afficher_table(table_hachage* ht)
{
    unsigned int i;
    printf("{");
    for(i=0;i<ht->capacite;i++)
    {
        printf("%d : ", i);
        liste_afficher(ht->table[i]);
    }
    printf("}\n");
}

void hash_destroy(table_hachage* ht, void (delete_func)(void*))
{
    unsigned int i;
    for(i=0;i<ht->capacite;i++)
    {
        liste_destroy(ht->table[i], delete_func);
    }
    free(ht->table);
}

bool verifHash(char* mot, void* struct_donne)
{
    elem e = element_new(mot);

    if(!hash_est_present(e, struct_donne, hash_str, element_compare))
    {
        //printf("%s incorrect\n", mot);
        element_delete(e);
        return false;
    }
    element_delete(e);
    return true;
}

void lectureHash(char* mot, void* struct_donne)
{
    elem e = element_new(mot);
    hash_inserer_redimensionner(e, struct_donne, hash_str, element_compare);
}

void empty(void* e)
{
    return;
}