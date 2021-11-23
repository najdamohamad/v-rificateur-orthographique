#include "linked_list.h"
#include<stdbool.h>


liste create_liste()
{
    return NULL;
}

void afficher(liste l)
{
    liste copy_l = l ; 
    while(copy_l != NULL)
    {
        printf("(") ; 
        element_print(copy_l->e) ;
        printf(")-->");

        copy_l = copy_l->next ; 
    }
    printf("\n");
}

void add_last(T e , liste* l)
{
    liste last_element = calloc(1, sizeof(*last_element)) ;
    last_element->e = e;
    liste copy_l = *l;
    
    if(*l == NULL)
    {
        *l = last_element;
        return;
    }
        
    while (copy_l->next != NULL)
    {
        copy_l = copy_l->next;
    }
    copy_l->next = last_element;

}

bool liste_element_exist( T e , liste l)
{
    liste copy_l = l ;
    while (copy_l->next != NULL )
    {
        if(copy_l->e == e)
        return true ;
        copy_l = copy_l->next ;
    }
    return false ;
    
}

void add_first(T e, liste* l)
{
    liste new_element = calloc(1, sizeof(*new_element));
    new_element->e = e;
    new_element->next = *l ;
    *l = new_element ;
}

void destroy(liste l)
{
    if(l == NULL)
    {
        return;
    }
    else
    {
        liste ptr_next, ptr = l ;

        while(ptr != NULL)
        {
            ptr_next = ptr->next;

            element_delete(ptr->e);
            free(ptr);

            ptr = ptr_next;
        }
    }
}

void* liste_get_element(liste l, int indice)
{
    for(int i = 0; i < indice; i++)
    {
        l = l->next;
    }
    return l->e;
}




