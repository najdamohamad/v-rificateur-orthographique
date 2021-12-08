#include <stdio.h>
#include <stdlib.h>

#include "lecture.h"

void testLecture(char* mot, void* structure)
{
    printf("#lect# %s\n", mot);
}

bool testVerif(char* mot, void* structure)
{
    printf("#verif# %s\n", mot);
    return false;
}

int main(int argc, char *argv[])
{
    FILE *dictionnaire, *texte;

    //ouvre les fichiers en lecture uniquement
    dictionnaire = fopen("data/FR_aleger.txt", "r"); 
    if(dictionnaire == NULL)
    {
        printf("\nERREUR FATALE : DICTIONNAIRE INTROUVABLE\n");
        printf("Essayez data/FR.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }

    texte = fopen("data/simpletest.txt", "r");
    if(texte == NULL)
    {
        printf("\nERREUR FATALE : TEXTE INTROUVABLE\n");
        printf("Essayez data/a_la_recherche_du_temps_perdu.txt et vérifiez que le fichier est présent dans le dossier data\n");
        return EXIT_FAILURE;
    }

    void* structure = NULL;
    lecture_dico(dictionnaire, structure, testLecture, -1);

    int total = 0, nb_err = 0;
    nb_err = lecture(texte, structure, testVerif, -1 , &total);
    printf("Nombre de mots vérifs : %d et %d erreurs\n", total, nb_err);


    fclose(texte);
    fclose(dictionnaire);
}