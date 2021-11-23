// #include "arbre_prefix.h"

// //FONCTIONS GENERIQUES

// noeud* creer_noeud(T elem, bool final)
// {
//     noeud* n = calloc(1, sizeof(*n));

//     n->fils = liste_create();
//     n->val = elem;
//     n->final = final;

//     return n;
// }

// bool arbre_est_vide(arbre a)
// {
//     return a == NULL;
// }

// void detruire_arbre(arbre a)
// {
//     if(arbre_est_vide(a))
//         return;


//     detruire_arbre(a->fils->e);

//     liste_destroy(a->fils);
//     free(a);
// }

// // unsigned hauteur(arbre a)
// // {
// //     if(arbre_est_vide(a))
// //         return 0;
    
// //     unsigned hd = 0, hg = 0;
    
// //     if(!arbre_est_vide(a->filsDroit))
// //     {
// //         hd++;
// //         hd += hauteur(a->filsDroit);
// //     }
// //     if(!arbre_est_vide(a->filsGauche))
// //     {
// //         hg++;
// //         hg += hauteur(a->filsGauche);
// //     }

// //     return hd > hg ? hd : hg;
// // }

// // unsigned nb_noeuds(arbre a)
// // {
// //     if(arbre_est_vide(a))
// //         return 0;

// //     unsigned n = 1;
    
// //     n += nb_noeuds(a->filsDroit);
// //     n += nb_noeuds(a->filsGauche);
        
// //     return n;
// // }

// // unsigned nb_feuilles(arbre a)
// // {
// //     if(arbre_est_vide(a))
// //         return 0;
// //     if(arbre_est_vide(a->filsGauche) && arbre_est_vide(a->filsDroit))
// //         return 1;
    
// //     unsigned n = 0;
    
// //     n += nb_feuilles(a->filsDroit);
// //     n += nb_feuilles(a->filsGauche);
    
// //     return n;
// // }

// // void parcours_prefixe(arbre a)
// // {
// //     if(arbre_est_vide(a))
// //         return;

// //     printf("(%d)->",a->val);

// //     parcours_prefixe(a->filsGauche);
// //     parcours_prefixe(a->filsDroit);

// // }

// // void ajouter_elem(T elem)
// // {

// // }

// // bool verif_elem(T elem)
// // {
    
// // }