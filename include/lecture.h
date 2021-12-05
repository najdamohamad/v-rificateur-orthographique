#ifndef _LECTURE_H
#define _LECTURE_H

//LIBRAIRIES
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//CONSTANT
#define MAX_CARAC_PER_LINE 20000
#define WORDS_SEPARATORS " ,.:;!?/\n\\\"\'-()_*`‘"
#define END_OF_FILE -1
#define MAX_CARAC_WORD 27

//FONCTIONS
int lecture(FILE* texte, void* struct_donne, bool (func)(char*, void*), int nb_max , int *total);      //Vérifie le texte avec la fonction de teste verif_func
void lecture_dico(FILE* texte, void* struct_donne, void (func)(char*, void*), int nb_max);
void free_tab_char(char** c, int nb);                   //Libère la mémoire d'un tableau de char de nb éléments
char** get_next_line_into_words(FILE* pf, int* nb_word);//Transfome la prochaine ligne de pf en tableau de char mots ET alloue la mémoire
int words_count(char* phrase);                          //Compte le nombre de mots dans la phrase
char *strdup(const char *c);                            //Copie une chaine de caractère et réalloue la mémoire

#endif