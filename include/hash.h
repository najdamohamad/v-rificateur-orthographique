#ifndef _HASH_H
#define _HASH_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "element.h"
#include"linked_liste.h"

//STRUCTURES
typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;


//FONCTIONS GENERIQUES
//IMPLEMENTATION
T new_elem(float lat, float lon);
table_hachage new_hash(unsigned capacite);
int hash(T element, unsigned capacite);
bool hash_identiques(T element_1, T element_2);
bool est_present(T element, table_hachage* ht);
void inserer_sans_redimensionner(T element, table_hachage* ht);
void afficher_table(table_hachage* ht);
void destroy_hash(table_hachage* ht);
void inserer_redimensionner(T element, table_hachage* ht);

#endif