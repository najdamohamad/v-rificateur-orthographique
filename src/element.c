#include "element.h"

elem element_new(char* mot)
{
    elem e = calloc(1, sizeof(*e));
    e->mot = calloc(strlen(mot) + 1, sizeof(char));

    if (e->mot != NULL)
       strcpy(e->mot, mot);

    return e;
}

int element_compare(void* e1, void* e2)
{
    return strcmp(((elem)e1)->mot, ((elem)e2)->mot);
}

void element_print(elem e)
{
    printf("%s",e->mot);
}

char element_get(elem e, int i)
{
    return e->mot[i];
}

void element_delete(void* e)
{
    free(((elem)e)->mot);
    free(((elem)e));
}

int element_length(elem e)
{
    return strlen(e->mot);
}