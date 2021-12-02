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
bool liste_element_exist(void* e, liste l);
void* liste_get_element(liste l, int indice);
void liste_add_last(void* e , liste* l);
void liste_add_first(void* e, liste* l);
void liste_destroy(liste l);

bool verifListe(char* mot, void* struct_donne);
void lectureListe(char* mot, void* struct_donne);
#endif