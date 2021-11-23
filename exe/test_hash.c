#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <time.h>

int main(void)
{
    clock_t begin = clock();

    table_hachage ht = hash_new(1);
    int i, nb = 10;
    char str[255];
    for(i=0;i<nb;i++)
    {
        sprintf(str, "%d", i);
        hash_inserer_redimensionner(element_new(str), &ht);
    }


    hash_afficher_table(&ht);

    hash_destroy(&ht);

    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis ); 
    return EXIT_SUCCESS;
}
