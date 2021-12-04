#ifndef _ARBRE_RADIX_H
#define _ARBRE_RADIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arbre_prefix.h"
#include "hash.h"

void transform_prefix_into_radix(arbre* a);
arbre partage_suffix(arbre a, table_hachage* alr_meet, bool* reloc);

void detruire_arbre_radix(arbre a, table_hachage* duplic);
void radix_delete(void* e);

elem suffix_conc(arbre a);
int suffix_compare(void* e1, void* e2);
void chuuuuuu(void*);
int hash_suffix(void* e, unsigned c);

#endif