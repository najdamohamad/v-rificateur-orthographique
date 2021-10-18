#include "lecture.h"
#include <string.h>

//FONCTIONS GENERIQUES
//Fonction générique de vérification de fichier texte
//Paramètres : le texte et la fonction spécifique de vérification de correcte écriture
void verif(FILE* texte, void (*verif_func)(void))
{
    int nb_words;
    char ** mots = get_next_line_into_words(texte, &nb_words);

    while (nb_words != END_OF_FILE)
    {
        for(int i = 0; i < nb_words; i++)
        {
            if(mots[i] == NULL)
                printf("\nERREUR LECTURE\n");
            
            printf("%s\n", mots[i]);
            getchar();
            //verif_func(mots[i]);
        }
        free_tab_char(mots, nb_words);
        mots = get_next_line_into_words(texte, &nb_words);
    }

    printf("\nFin de la vérification du fichier texte\n");
}

void free_tab_char(char** c, int nb)
{
    for(int i = 0; i < nb; i++)
        free(c[i]);
    free(c);
}

char** get_next_line_into_words(FILE* pf, int* nb_word)
{
    *nb_word = -1;
    char ligne [MAX_CARAC_PER_LINE];
    if(ligne == NULL)
    {
        printf("\nERREUR MEMOIRE LIGNE\n");
        return NULL;
    }

    //Récupère la ligne avec MAX_CARAC_PER_LINE caractères max
    //par ligne et si rien n'est récupéré, renvoie l'indication de la fin de fichier
    if(fgets(ligne, MAX_CARAC_PER_LINE, pf) == NULL)
        return NULL;
    
    //Découpe la ligne en tableau de mots en allouant la mémoire
    char* tmp;
    char* ligne_tmp = strdup(ligne);
    *nb_word = words_count(ligne_tmp);
    free(ligne_tmp);
    if(nb_word == 0)
        return NULL;
        
    
    //Allocation du tableau de mots en fonction du nombre de mots
    // +1 pour laisser une case NULL pour marquer la fin de la liste de mots
    char** mots = calloc(*nb_word+1, sizeof(*mots));
    if(mots == NULL)
    {
        printf("Erreur Allocation mots\n");
        *nb_word = -1;
        return NULL;
    }
    
    //Trouve le mot et copie en allouant la mémoire dans le tableau de mots
    int i = 0;
    tmp = strtok(ligne, WORDS_SEPARATORS);
    if(tmp != NULL)
        mots[i] = strdup(tmp);

    while (tmp != NULL)
    {
        i++;
        tmp = strtok(NULL, WORDS_SEPARATORS);

        if(tmp != NULL)
            mots[i] = strdup(tmp);
    }

    return mots;
}

int words_count(char* phrase)
{
    int count = 0;
    char* mot = strtok(phrase, WORDS_SEPARATORS);
    while (mot != NULL)
    {
        count++;
        mot = strtok(NULL, WORDS_SEPARATORS);
    }
    return count;
}

char *strdup(const char *c)
{
    assert(c != NULL);

    char *dup = malloc(strlen(c) + 1);

    if (dup != NULL)
       strcpy(dup, c);

    return dup;
}