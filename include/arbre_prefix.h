#ifndef _ARBRE_PRE_H
#define _ARBRE_PRE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "arbre_bin.h"

bool recherche_arbre_prefix(arbre a , elem e);
void ajout_prefix(arbre* a, elem e);

#endif