#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lecture.h"
#include "hash.h"
#include "linked_list.h"
#include "arbre_radix.h"

//PARAMETERS
//Nombre de mots a lire : -1 pour tout lire
#define Nb_Dico -1
#define Nb_Lecture -1


int main(int argc, char *argv[])
{
    //Vérifie que le programme est bien lancé avec 2 arguments
    if(argc != 3)
    {
        printf("\nERREUR FATALE : MAUVAIS ARGUMENTS\n");
        printf("Exemple d'utilisation : ./bin/Final data/FR.txt data/a_la_recherche_du_temps_perdu.txt\n");
        return EXIT_FAILURE;
    }

    //Tente d'accéder aux 2 fichiers donnés en paramètres
    //Quitte si les fichies sont illisibles ou inexistants
    FILE *dictionnaire, *texte;
    //ouvre les fichiers en lecture uniquement
    dictionnaire = fopen(argv[1], "r"); 
    if(dictionnaire == NULL)
    {
        printf("\nERREUR FATALE : DICTIONNAIRE INTROUVABLE\n");
        printf("Essayez data/FR.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }

    texte = fopen(argv[2], "r");
    if(texte == NULL)
    {
        printf("\nERREUR FATALE : TEXTE INTROUVABLE\n");
        printf("Essayez data/a_la_recherche_du_temps_perdu.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }


    //********************************************TESTS********************************************

    //************* METHODE 3 : ARBRES PREFIX

    arbre a = NULL;

    //Lecture du dictionnaire
    lecture_dico(dictionnaire, &a, lectureArbre, Nb_Dico);


    //Vérification du texte
    int nb;
    //lecture(texte, a, verifArbre, Nb_Lecture, &nb);


    //Liberation mémoire
    fclose(texte);
    fclose(dictionnaire);

    //************* METHODE 4 : ARBRE RADIX OPTIMISE

    texte = fopen(argv[2], "r");

    transform_prefix_into_radix(&a);
    
    table_hachage reloc_tmp = hash_new(1); 
    bool useless;
    a = partage_suffix(a, &reloc_tmp, &useless);
    hash_destroy(&reloc_tmp, chuuuuuu);


    //Vérification du texte
    lecture(texte, a, verifArbre, Nb_Lecture, &nb);

    //Liberation mémoire
    
    fclose(texte);
    table_hachage duplic = hash_new(1);
    detruire_arbre_radix(a, &duplic);
    hash_destroy(&duplic, radix_delete);
    
    return EXIT_SUCCESS;
}