#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <assert.h>

//Structure d'un élément (ici juste un mot)
typedef struct mot {
  char* mot;
} *elem;

//Crée un nouvel élément
elem element_new(char* mot);
//Copare deux éléments
int element_compare(void* e1, void* e2);
//Affiche un element
void element_print(elem e);
//Donne la lettre a l'indice i de l'élément
char element_get(elem e, int i);
//Supprime l'élément
void element_delete(void* e);
//Donne la taille du mot de l'élément
int element_length(elem e);

#endif