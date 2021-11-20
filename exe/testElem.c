#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include <time.h>

int main(void)
{
    clock_t begin = clock();

    T e1 = element_new("coucou");
    T e2 = element_new(" salut");
    T e3 = element_new(" ça va ?");

    element_print(e1);
    element_print(e2);
    element_print(e3);

    printf("\nComparaison e1 et e2 : %d\n", element_compare(e1, e2));

    element_delete(e1);
    element_delete(e2);
    element_delete(e3);

    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf( "Finished in %ld ms\n", millis ); 
    return EXIT_SUCCESS;
}
