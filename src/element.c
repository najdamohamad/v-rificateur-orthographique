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

int element_compare_n_to_m(elem e1, elem e2, int n, int m)
{
    if(strlen(e1->mot) < (long unsigned int)m || strlen(e2->mot) < (long unsigned int)m)
        return -1;
    return strncmp(e1->mot+n, e2->mot+n, m-n);
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

void* element_copy(void* e)
{
    elem new = element_new(((elem)e)->mot);
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