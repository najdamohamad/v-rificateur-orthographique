#ifndef _ARBRE_RADIX_H
#define _ARBRE_RADIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arbre_prefix.h"
#include "hash.h"

//Transforme un arbre prefix en radix :o
void transform_prefix_into_radix(arbre* a);
//Compression 2 : trouve les répétitions dans l'arbre et tente de les réduires
arbre partage_suffix(arbre a, table_hachage* alr_meet, bool* reloc);

//Supprime l'arbre en ignorant les noeuds dédoublés (marquage) et les ajoute dans une liste ou table de hash
void detruire_arbre_radix(arbre a, table_hachage* duplic);

//Fonctions annexes pour structures
void radix_delete(void* e);             //Suprime un noeud radix
int suffix_compare(void* e1, void* e2); //Compare deux arbres
void chuuuuuu(void*);                   //Fonction vide
int hash_suffix(void* e, unsigned c);   //Calcule le hash de la valeur du noeud

#endif