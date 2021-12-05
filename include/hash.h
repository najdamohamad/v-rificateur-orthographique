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
  unsigned capacite;          /* capacité de la table */
  unsigned nb_elements;       /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;

//Crée une nouvelle table
table_hachage hash_new(unsigned capacite);
//Fonction de hashage pour un elem
int hash_str(void* element, unsigned capacite);

//Vérifie si l'elément est deja présent dans la table
void* hash_est_present(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));
//ajoute un élément sans redimentionner la table
void hash_inserer_sans_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));
//Affiche toute la table
void hash_afficher_table(table_hachage* ht);
//Détruit la table et ses éléments en utilisant delete_func
void hash_destroy(table_hachage* ht, void (delete_func)(void*));
//Ajoute un element en redimentionnant si besoin (nb elements >= capacité)
void hash_inserer_redimensionner(void* element, table_hachage* ht, int (hash_func)(void*, unsigned int),int (cmp_func) (void*, void*));

//Fonction vide pour supprimer la table sans supprimer ses éléments
void empty(void* e);

//Fonctions utiles pour le test final
void lectureHash(char* mot, void* struct_donne);
bool verifHash(char* mot, void* struct_donne);
#endif