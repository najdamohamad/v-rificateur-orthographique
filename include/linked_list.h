#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>

#include"element.h"

typedef struct node{
  void* e ;
  struct node* next;
}*liste;

liste create_liste();
void afficher(liste l );
void add_last(T e , liste* l);
void add_first(T e, liste* l);
void destroy(liste l);

#endif