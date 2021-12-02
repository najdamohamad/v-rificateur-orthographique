#ifndef _ARBRE_RADIX_H
#define _ARBRE_RADIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arbre_prefix.h"
#include "linked_list.h"

void transform_prefix_into_radix(arbre* a);
arbre partage_prefix(arbre a, liste* alr_meet, liste* duplic);
void detruire_arbre_radix(arbre a, liste l);

void radix_list_delete(void* e);
elem prefix_conc(arbre a);

int prefix_compare(void* e1, void* e2);
void chuuuuuu(void*);

#endif