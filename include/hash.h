#ifndef _HASH_H
#define _HASH_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "element.h"
#include "linked_list.h"

//STRUCTURES
typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;


//FONCTIONS GENERIQUES
//IMPLEMENTATION
table_hachage hash_new(unsigned capacite);
int hash_str(void* element, unsigned capacite);

void* hash_est_present(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));
void hash_inserer_sans_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));
void hash_afficher_table(table_hachage* ht);
void hash_destroy(table_hachage* ht, void (delete_func)(void*));
void hash_inserer_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));

void empty(void* e);

void lectureHash(char* mot, void* struct_donne);
bool verifHash(char* mot, void* struct_donne);
#endif