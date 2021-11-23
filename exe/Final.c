#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lecture.h"
#include "hash.h"
#include "linked_list.h"

void test(char* mot, void* unused)
{
    unused = unused;
    printf("%s\n", mot);
    //getchar();
}

// void lectureHash(char* mot, void* struct_donne)
// {
//     T e = element_new(mot);
//     inserer_redimensionner(e, struct_donne);
// }

void lectureListe(char* mot, void* struct_donne)
{
    T e = element_new(mot);
    liste_add_first(e, struct_donne);
}

// void verifHash(char* mot, void* struct_donne)
// {
//     T e = element_new(mot);
//     if(!est_present(e, struct_donne))
//     {
//         printf("%s incorrect\n", mot);
//         //getchar();
//     }

//     element_delete(e);
// }

void verifListe(char* mot, void* struct_donne)
{
    T e = element_new(mot);
    if(!liste_element_exist(e, struct_donne))
    {
        printf("%s incorrect\n", mot);
        //getchar();
    }

    element_delete(e);
}
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

    //*************METHODE 1 : Linked list


      begin = clock();

    liste l = liste_create() ;
    //Lecture du dictionnaire
    printf("Debut lecture...\n");
    lecture_dico(dictionnaire, l, lectureListe);
    time_ms_dico = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;
    printf("Temps dico (ms): %ld\n", time_ms_dico);

    //Vérification du texte
    begin = clock();
    lecture(texte, l, verifListe);
    time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Debug : affichage
    liste_afficher(l);
    //Liberation mémoire
    fclose(dictionnaire);
    fclose(texte);
    liste_destroy(l);

    printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
    printf("\nFIN DU PROGRAMME\n");
    return EXIT_SUCCESS;



}
    
    //*************METHODE 2 : TABLE DE HASHAGE

//     begin = clock();

//     table_hachage ht = new_hash(1);
//     //Lecture du dictionnaire
//     printf("Debut lecture...\n");
//     lecture_dico(dictionnaire, &ht, lectureHash);
//     time_ms_dico = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;
//     printf("Temps dico (ms): %ld\n", time_ms_dico);

//     //Vérification du texte
//     begin = clock();
//     lecture(texte, &ht, verifHash);
//     time_ms_verif = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

//     //Debug : affichage
//     afficher_table(&ht);

//     //Liberation mémoire
//     fclose(dictionnaire);
//     fclose(texte);
//     destroy_hash(&ht);

//     printf("Temps dico (ms): %ld\nTemps verif (ms): %ld\n", time_ms_dico, time_ms_verif);
//     printf("\nFIN DU PROGRAMME\n");
//     return EXIT_SUCCESS;
// }