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
    clock_t begin;
    unsigned long time_ms_dico,time_ms_verif;
    int nb_error;
    int total;

    //************* METHODE 1 : Linked list
    
    //Lecture du dictionnaire
    printf("--- DEBUT TEST LISTE\n");
    begin = clock();
    liste l = liste_create() ;
    lecture_dico(dictionnaire, &l, lectureListe, Nb_Dico);
    
    time_ms_dico = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Vérification du texte
    begin = clock();
    if(Nb_Lecture >= 1000 || Nb_Lecture == -1 )//On limite car trop de temps
        nb_error = lecture(texte, l, verifListe, 1000, &total);
    else
        nb_error = lecture(texte, l, verifListe, Nb_Lecture , &total);
        
    printf("nombre d'erreurs : %d sur %d  \n", nb_error , total);

    time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Liberation mémoire
    fclose(dictionnaire);
    fclose(texte);
    liste_destroy(l, element_delete);

    printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    printf("--- FIN TEST LISTE\n");

    
    //************* METHODE 2 : TABLE DE HASHAGE
    printf("--- DEBUT TEST HASH\n");
    dictionnaire = fopen(argv[1], "r");
    texte = fopen(argv[2], "r");
    begin = clock();

    table_hachage ht = hash_new(1);

    //Lecture du dictionnaire
    lecture_dico(dictionnaire, &ht, lectureHash, Nb_Dico);

    time_ms_dico = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Vérification du texte
    begin = clock();
    nb_error = lecture(texte, &ht, verifHash, Nb_Lecture , &total);
    printf("nombre d'erreurs : %d sur %d  \n", nb_error , total);

    time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Liberation mémoire
    fclose(dictionnaire);
    fclose(texte);
    hash_destroy(&ht, element_delete);

    printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    printf("--- FIN TEST HASH\n");
    

    //************* METHODE 3 : ARBRES PREFIX
    printf("--- DEBUT TEST PREFIX\n");
    dictionnaire = fopen(argv[1], "r");
    texte = fopen(argv[2], "r");
    begin = clock();

    arbre a = NULL;

    //Lecture du dictionnaire
    lecture_dico(dictionnaire, &a, lectureArbre, Nb_Dico);

    time_ms_dico = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Vérification du texte
    begin = clock();
    nb_error = lecture(texte, a, verifArbre, Nb_Lecture , &total);
    printf("nombre d'erreurs : %d sur %d  \n", nb_error , total);
    time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;


    //Liberation mémoire
    fclose(texte);
    fclose(dictionnaire);

    printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    printf("--- FIN TEST PREFIX\n");

    //************* METHODE 4 : ARBRE RADIX OPTIMISE

    printf("--- DEBUT TEST RADIX\n");
    texte = fopen(argv[2], "r");
    begin = clock();

    transform_prefix_into_radix(&a);
    
    //Compression des suffixes
    table_hachage reloc_tmp = hash_new(1); 
    bool useless;
    a = partage_suffix(a, &reloc_tmp, &useless);
    hash_destroy(&reloc_tmp, chuuuuuu);

    time_ms_dico += (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Vérification du texte
    begin = clock();
    nb_error = lecture(texte, a, verifArbre, Nb_Lecture , &total);
    printf("nombre d'erreurs : %d sur %d  \n", nb_error , total);
    time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Liberation mémoire
    
    fclose(texte);

    table_hachage duplic = hash_new(1);
    detruire_arbre_radix(a, &duplic);
    hash_destroy(&duplic, radix_delete);

    printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    printf("--- FIN TEST RADIX\n");
    
    return EXIT_SUCCESS;
}