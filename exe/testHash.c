#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <time.h>

int main(void)
{
    clock_t begin = clock();

    table_hachage ht = new_hash(1);
    int i, nb = 1000000;
    char str[255];
    for(i=0;i<nb;i++)
    {
        sprintf(str, "%d", i);
        inserer_redimensionner(element_new(str), &ht);
    }


    afficher_table(&ht);

    destroy_hash(&ht);

    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis ); 
    return EXIT_SUCCESS;
}
