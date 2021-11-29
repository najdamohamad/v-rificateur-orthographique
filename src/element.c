#include "element.h"

elem element_new(char* mot)
{
    elem e = calloc(1, sizeof(*e));
    e->mot = malloc(strlen(mot) + 1);

    if (e->mot != NULL)
       strcpy(e->mot, mot);

    return e;
}

int element_compare(elem e1, elem e2)
{
    return strcmp(e1->mot, e2->mot);
}

int element_compare_n(elem e1, elem e2, int n)
{
    return strncmp(e1->mot, e2->mot, n);
}

void element_print(elem e)
{
    printf("%s",e->mot);
}

char element_get(elem e, int i)
{
    return e->mot[i];
}

void element_delete(elem e)
{
    free(e->mot);
    free(e);
}

int element_length(elem e)
{
    return strlen(e->mot);
}

elem element_copy(elem e)
{
    elem new = element_new(e->mot);
    return new;
}

elem element_copy_n(elem e, int n)
{
    char* mot = calloc(n+1, sizeof(char));

    assert(n <= element_length(e));

    strncpy(mot, e->mot, n);

    strcat(mot, "\0");
    elem new = element_new(mot);

    free(mot);
    return new;
}