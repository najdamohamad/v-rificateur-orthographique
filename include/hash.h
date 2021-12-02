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
int hash(elem element, unsigned capacite);
bool hash_identiques(elem element_1, elem element_2);
bool hash_est_present(elem element, table_hachage* ht);
void hash_inserer_sans_redimensionner(elem element, table_hachage* ht);
void hash_afficher_table(table_hachage* ht);
void hash_destroy(table_hachage* ht);
void hash_inserer_redimensionner(elem element, table_hachage* ht);

void lectureHash(char* mot, void* struct_donne);
bool verifHash(char* mot, void* struct_donne);
#endif