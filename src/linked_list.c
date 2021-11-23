#include "linked_list.h"


liste create_liste(T e)
{
    liste l = malloc(sizeof(liste));
    l->e = e ;
    l->next = NULL ; 
}

void afficher(liste l )
{
    liste copy_l = l ; 
    while(copy_l->next != NULL)
    {
        printf("(") ; 
        element_print(l->e) ;
        printf(")-->");

        copy_l = copy_l->next ; 
    }
}

void add_last(T e , liste l)
{
    liste last_element = create_liste(e) ; 
    liste copy_l = l ;
    while (copy_l->next != NULL)
    {
        copy_l = copy_l->next;
    }
    copy_l->next = last_element ; 
    l = copy_l ;
    
}

void add_First(T e, liste* l)
{
    liste new_element = create_liste(e);
    new_element->next = l ;
    l = new_element ;
}

void destroy(liste l)
{
    if(l == NULL)
    {
        return;
    }
    else
    {
        liste ptr = l ;
        liste ptr_next = l->next ;

        While(ptr != NULL)
        {
            free(ptr);
            ptr = ptr_next ;

            if(ptr_next != NULL)
            {
             ptr_next = ptr_next->next;
            }
           
        }

    }
}




