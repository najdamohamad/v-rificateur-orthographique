#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"element.h"

typedef struct node{
  void* e ;
  struct node* next;
}*liste;

liste liste_create();
void liste_afficher(liste l );
void* liste_element_exist(void* e, liste l, int (cmp_func) (void*, void*));
void* liste_get_element(liste l, int indice);
void liste_add_last(void* e , liste* l);
void liste_add_first(void* e, liste* l);
void liste_destroy(liste l, void (del_func)(void*));

bool verifListe(char* mot, void* struct_donne);
void lectureListe(char* mot, void* struct_donne);
#endif