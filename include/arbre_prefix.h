#ifndef _ARBRE_PREFIX_H
#define _ARBRE_PREFIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "element.h"
#include "linked_list.h"

//STRUCTURES
typedef struct noeud
{
    T val;
    liste fils;
    bool final;
}noeud;

typedef noeud* arbre;

//FONCTIONS GENERIQUES
arbre creer_arbre();
void detruire_arbre(arbre a);

void ajouter_fils(noeud* noeud, T elem, bool final);
bool noeud_est_vide(noeud* noeud);

// unsigned hauteur(arbre a);
// unsigned nb_noeuds(arbre a);
// unsigned nb_feuilles(arbre a);

void parcours_prefixe(arbre a);

void ajouter_elem(T elem);
bool verif_elem(T elem);

#endif