#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lecture.h"

void test(char* mot)
{
    printf("%s\n", mot);
    //getchar();
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

    clock_t begin;
    unsigned long time_ms;

    //METHODE 1 : TABLE DE HASHAGE
    begin = clock();
    //Lecture du dictionnaire 
    lecture_dico(dictionnaire, test);
    time_ms = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Vérification du texte
    begin = clock();
    lecture(texte, test);
    time_ms = (clock() -  begin) * 1000 / CLOCKS_PER_SEC;

    //Liberation mémoire
    fclose(dictionnaire);
    fclose(texte);

    printf("Temp dico : %ld\n",time_ms);
    printf("\nFIN DU PROGRAMME\n");
    return EXIT_SUCCESS;
}
