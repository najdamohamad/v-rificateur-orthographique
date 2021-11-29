#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct mot {
  char* mot;
} *elem;

elem element_new(char* mot);
int element_compare_n(elem e1, elem e2, int n);
int element_compare(elem e1, elem e2);
void element_print(elem e);
char element_get(elem e, int i);
void element_delete(elem e);
int element_length(elem e);
elem element_copy_n(elem e, int n);

#endif