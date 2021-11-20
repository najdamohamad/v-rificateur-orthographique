#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct mot {
  char* mot;
} *T;

T element_new(char* mot);
int element_compare(T e1, T e2);
void element_print(T e);
char element_get(T e, int i);
void element_delete(T e);
int element_length(T e);
T element_copy(T e);

#endif