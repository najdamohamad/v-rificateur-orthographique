#include "element.h"

T element_new(char* mot)
{
    T e = calloc(1, sizeof(*e));
    e->mot = malloc(strlen(mot) + 1);

    if (e->mot != NULL)
       strcpy(e->mot, mot);

    return e;
}

int element_compare(T e1, T e2)
{
    return strcmp(e1->mot, e2->mot);
}

void element_print(T e)
{
    printf("%s\n",e->mot);
}

char element_get(T e, int i)
{
    return e->mot[i];
}

void element_delete(T e)
{
    free(e->mot);
    free(e);
}

int element_length(T e)
{
    return strlen(e->mot);
}

T element_copy(T e)
{
    T new = element_new(e->mot);
    return new;
}