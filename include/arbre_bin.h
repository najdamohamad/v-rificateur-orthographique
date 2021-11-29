#ifndef _ARBRE_BIN_H
#define _ARBRE_BIN_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "element.h"

//STRUCTURES
typedef struct noeud
{
    elem val;
    struct noeud* frere;
    struct noeud* fils;
    bool final;
}noeud;

typedef noeud* arbre;

//FONCTIONS GENERIQUES
noeud* creer_noeud(elem valeur);
bool arbre_est_vide(arbre a);
void detruire_arbre(arbre a);

unsigned hauteur(arbre a);
unsigned nb_noeuds(arbre a);
unsigned nb_feuilles(arbre a);
void parcours_prefixe(arbre a);

#endif